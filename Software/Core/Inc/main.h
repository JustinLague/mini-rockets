/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SPI1_CS_ALTIMITER_Pin GPIO_PIN_3
#define SPI1_CS_ALTIMITER_GPIO_Port GPIOA
#define SPI1_CS_IMU_Pin GPIO_PIN_4
#define SPI1_CS_IMU_GPIO_Port GPIOA
#define INT2_Pin GPIO_PIN_4
#define INT2_GPIO_Port GPIOC
#define INT1_Pin GPIO_PIN_5
#define INT1_GPIO_Port GPIOC
#define SPI2_CS_MEMORY_Pin GPIO_PIN_11
#define SPI2_CS_MEMORY_GPIO_Port GPIOB
#define HOLD_Pin GPIO_PIN_13
#define HOLD_GPIO_Port GPIOB
#define CS_Pin GPIO_PIN_14
#define CS_GPIO_Port GPIOB
#define LED_1_Pin GPIO_PIN_15
#define LED_1_GPIO_Port GPIOB
#define LED_2_Pin GPIO_PIN_6
#define LED_2_GPIO_Port GPIOC
#define LED_3_Pin GPIO_PIN_7
#define LED_3_GPIO_Port GPIOC
#define LED_4_Pin GPIO_PIN_8
#define LED_4_GPIO_Port GPIOC
#define BUZZER_Pin GPIO_PIN_15
#define BUZZER_GPIO_Port GPIOA
#define SENSE_2_Pin GPIO_PIN_10
#define SENSE_2_GPIO_Port GPIOC
#define FIRE_2_Pin GPIO_PIN_11
#define FIRE_2_GPIO_Port GPIOC
#define SENSE_1_Pin GPIO_PIN_12
#define SENSE_1_GPIO_Port GPIOC
#define FIRE_1_Pin GPIO_PIN_2
#define FIRE_1_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
