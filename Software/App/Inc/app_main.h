#ifndef APP_MAIN_H_#define APP_MAIN_H_

#include "kalman.h"
#include "buffer.h"

/******************************************************************************/
/*                              Type  Prototype                               */
/******************************************************************************/
typedef struct {
	kalman_t kalman;

	float altimeter_ground_altitude; // mean sea level altitude
	float altimeter_agl_altitude;    // above ground level altitude
	float altimeter_velocity;
	float altimeter_acceleration;

	float imu_velocity;
	float imu_acceleration;
	float imu_angular_rate;

	uint32_t last_update;
	uint32_t calibrated;
} rocketdata_t;

typedef enum rocket_state {
	INITIALISATION,
	STANDBY_ON_PAD,
	LAUNCH,
	POWERED_ASCENT,
	ENGINE_BURNOUT,
	COASTING_ASCENT,
	APOGEE_REACHED,
	DROGUE_DEPLOYMENT,
	DROGUE_DESCENT,
	MAIN_DEPLOYMENT,
	MAIN_DESCENT,
	LANDING,
	RECOVERY,
	PICKEDUP
} rocket_state;

/******************************************************************************/
/*                             Function prototype                             */
/******************************************************************************/
void initMainTask();
void mainTask();

void rocketDataInit(rocketdata_t *_rocketdata);
void rocketDataCalibrate(rocketdata_t *_rocketdata);
void rocketDataUpdate(rocketdata_t *_rocketdata);
int apogeeDetection(rocketdata_t *_rocket_data);

float getVariance(buffer_t * callibration_buf);

/******************************************************************************/
/*                                Define                                      */
/******************************************************************************/
#define APP_ALTITUDE_CYCLE_MS         20
#define CALIBRATION_DELAY_MS         500
#define APOGEE_EJECTION_DELAY_MS     100 //delais d'ejection apres la detection d'apogee en millisec
#define ULTRASONIC_DELAY_MS         4000 //delais minimum apres le launch avant de pouvoir detection l'apogee en millisec
#define DELAY_SEPARATION_PAYLOAD    1000 //delais minimum apres la separation du nose cone de la fusee
#define LAUNCH_ACCEL_TRIGGER           5 // valeur proportionnelle a l'accel qui declanche le launch state
#define FLIGHT_ALTITUDE_TRIGGER      500 // altitude apres la detection du launch a laquelle on change d'etat en metre
#define MAIN_EJECTION_ALTITUDE       500 //altitude de deploiement du MAIN chute en metre



#endif /* APP_MAIN_H_ */
