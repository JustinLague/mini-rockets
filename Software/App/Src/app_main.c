#include "app_main.h"
#include "cmsis_os.h"
#include <stdio.h>
#include "SEGGER_RTT.h"
#include "main.h"
#include "app_buzzer.h"
#include "app_barometer.h"
#include "barometer.h"

const osThreadAttr_t mainHeader_attr = {
  .priority = (osPriority_t) osPriorityNormal, //Set initial thread priority to high
  .stack_size = 4096
};

//Calibration stuff
#define BUFFER_SIZE 20
buffer_t callibration_buf;
float buf_receive_data[BUFFER_SIZE];

void initMainTask() {
	osThreadNew(mainTask, NULL, &mainHeader_attr);
	SEGGER_RTT_WriteString(0, "Init main task\r\n");
}

__NO_RETURN void mainTask() {

	setBuzzerMode(BUZZER_SINGLETICK);

	uint32_t launch_tick = 0;
	rocketdata_t rocketdata;
	rocket_state myRocketState = INITIALISATION;
	rocket_state previous_myRocketState = INITIALISATION;

	rocketDataInit(&rocketdata);

	while (1) {
		rocketDataUpdate(&rocketdata);

		previous_myRocketState = myRocketState;

		switch (myRocketState) {

			case INITIALISATION:

				SEGGER_RTT_WriteString(0, "State: INITIALISATION \r\n");

				rocketDataCalibrate(&rocketdata);
				myRocketState = STANDBY_ON_PAD;

				break;

			case STANDBY_ON_PAD:

				if (rocketdata.altimeter_agl_altitude > FLIGHT_ALTITUDE_TRIGGER) {
					launch_tick = HAL_GetTick();
					myRocketState = POWERED_ASCENT;
				}

				break;

			case POWERED_ASCENT:

				SEGGER_RTT_WriteString(0, "State: POWERED_ASCENT \r\n");

				// Engine in burnout when acceleration below 0
				if ((HAL_GetTick() - launch_tick) > ULTRASONIC_DELAY_MS && rocketdata.altimeter_acceleration < 0) {
					myRocketState = COASTING_ASCENT;
				}

				break;

			case COASTING_ASCENT:

				SEGGER_RTT_WriteString(0, "State: COASTING_ASCENT \r\n");

				if (apogeeDetection(&rocketdata) == 1) {

					myRocketState = DROGUE_DESCENT;
				}

				break;

			case DROGUE_DESCENT:

				SEGGER_RTT_WriteString(0, "State: DROGUE_DESCENT \r\n");

				if (rocketdata.altimeter_agl_altitude < MAIN_EJECTION_ALTITUDE) {
					myRocketState = MAIN_DESCENT;
				}

				break;

			case MAIN_DESCENT:

				SEGGER_RTT_WriteString(0, "State: MAIN_DESCENT \r\n");

				//lorsque la fusee atteint le meme threshold que pour le flight mode
				if (rocketdata.altimeter_agl_altitude < FLIGHT_ALTITUDE_TRIGGER) {
					myRocketState = LANDING;
				}
				break;

			case LANDING:

				SEGGER_RTT_WriteString(0, "State: LANDING \r\n");

				//lorsque la vitesse n'est plus negative,
				if (rocketdata.altimeter_velocity > 0) {
					myRocketState = RECOVERY;
				}
				break;

			case RECOVERY:

				SEGGER_RTT_WriteString(0, "State: RECOVERY \r\n");

				break;

			default:

				SEGGER_RTT_WriteString(0, "State: DEFAULT \r\n");

				myRocketState = INITIALISATION;
				break;
			}

		if (previous_myRocketState != myRocketState) {
			//TODO: LOG THIS IN MEMORY SOMEHOW
		}

		osDelay(APP_ALTITUDE_CYCLE_MS);
	}
}

void rocketDataInit(rocketdata_t *_rocketdata) {
		kalman_init(&(_rocketdata->kalman));

		_rocketdata->altimeter_ground_altitude = 0;
		_rocketdata->altimeter_agl_altitude = 0;
		_rocketdata->altimeter_acceleration = 0;
		_rocketdata->altimeter_velocity = 0;

		_rocketdata->imu_acceleration = 0;
		_rocketdata->imu_velocity = 0;
		_rocketdata->imu_angular_rate = 0;

		_rocketdata->last_update = 0;
		_rocketdata->calibrated = 0;
}


// Set the MSL altitude
void rocketDataCalibrate(rocketdata_t *_rocketdata) {
	buffer_new(&callibration_buf, buf_receive_data, BUFFER_SIZE);

	float err = 0.0;

	while (!_rocketdata->calibrated) {

		osDelay(CALIBRATION_DELAY_MS);
 		rocketDataUpdate(_rocketdata);
		_rocketdata->altimeter_ground_altitude = _rocketdata->kalman.altitude;

		buffer_push(&callibration_buf, _rocketdata->altimeter_ground_altitude);

		//Small check to be sure this is the real ground altitude.
		err = getVariance(&callibration_buf);
		if (err < 2.0) {
			_rocketdata->calibrated = 1;
		}
	}
}

// Get new altitude, velocity and acceleration from the barometer and kalman filter
void rocketDataUpdate(rocketdata_t *_rocketdata) {
		/* Kalman filtering */
		float pressure = getPressure();

		kalman_update(&(_rocketdata->kalman), pressure_to_altitude(pressure), 0, (HAL_GetTick() - _rocketdata->last_update) / 1000.0f);
		_rocketdata->last_update = HAL_GetTick();

		_rocketdata->altimeter_agl_altitude= _rocketdata->kalman.altitude - _rocketdata->altimeter_ground_altitude;
		_rocketdata->altimeter_acceleration = _rocketdata->kalman.acceleration;
		_rocketdata->altimeter_velocity = _rocketdata->kalman.velocity;

		_rocketdata->imu_acceleration = /*something*/ 0;
		_rocketdata->imu_velocity = /*something*/ 0;
		_rocketdata->imu_angular_rate = /*something*/ 0;

		//find a way to pass this data to memory
}

// Calculate apogee detection
int apogeeDetection(rocketdata_t *_rocket_data) {

	int Apogee_Estimation = 0;
	//estimation de l'apogee
	//n,est valide qu'en coasting ascent
	// s(apogee) = s0 - 0.5 * v^2 / a
	Apogee_Estimation = _rocket_data->altimeter_agl_altitude - 0.5 * (_rocket_data->altimeter_velocity) * (_rocket_data->altimeter_velocity) / _rocket_data->altimeter_acceleration;

	//essaie pour contr� le sonic boom sans le delais
	//estime l'altitude de l'apogee et si la difference est trop grande
	//on annule le projet tu suite
	if (_rocket_data->altimeter_agl_altitude - Apogee_Estimation < 500) {
		//test supplementaire, l'acceleration se doit d'etre negative...
		if (_rocket_data->altimeter_acceleration < 0) {
			//lorsque la vitesse est negative, cest l'apogee
			if (_rocket_data->altimeter_velocity < 0) {
				//Apogee_Altitude = _kalman.altitude;
				return 1;
			}
		}
	}

	return 0;
}

float getVariance(buffer_t* callibration_buf) {
	float moyenne = 0, somme = 0, variance = 0;
	int i = 0;

	for (i = 0 ; i < BUFFER_SIZE ; i++) {
		  somme += callibration_buf->data[i];
	}

	moyenne = somme / BUFFER_SIZE;

	for (i = 0 ; i < BUFFER_SIZE ; i++) {
		  variance += (moyenne - callibration_buf->data[i]) * (moyenne - callibration_buf->data[i]);
	}

	return variance / BUFFER_SIZE;
}

