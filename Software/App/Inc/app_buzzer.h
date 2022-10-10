#ifndef APP_BUZZER_H_
#define APP_BUZZER_H_

/******************************************************************************/
/*                              Type  Prototype                               */
/******************************************************************************/


/******************************************************************************/
/*                             Function prototype                             */
/******************************************************************************/
void initBuzzerTask();
void buzzerTask();
void setBuzzerMode(int _imode);

/******************************************************************************/
/*                                Define                                      */
/******************************************************************************/
#define BUZZER_IDLE 0
#define BUZZER_SINGLETICK 1
#define BUZZER_DOUBLETICK 2
#define BUZZER_TRIPLETICK 3

#define CYCLE_TIME 1000
#define BEEP_LENGTH 1000

#endif /* APP_BUZZER_H_ */
