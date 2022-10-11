################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/app_barometer.c \
../App/Src/app_buzzer.c \
../App/Src/app_heartbeat.c \
../App/Src/app_imu.c \
../App/Src/app_main.c \
../App/Src/app_memory.c \
../App/Src/app_usb.c 

OBJS += \
./App/Src/app_barometer.o \
./App/Src/app_buzzer.o \
./App/Src/app_heartbeat.o \
./App/Src/app_imu.o \
./App/Src/app_main.o \
./App/Src/app_memory.o \
./App/Src/app_usb.o 

C_DEPS += \
./App/Src/app_barometer.d \
./App/Src/app_buzzer.d \
./App/Src/app_heartbeat.d \
./App/Src/app_imu.d \
./App/Src/app_main.d \
./App/Src/app_memory.d \
./App/Src/app_usb.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/%.o App/Src/%.su: ../App/Src/%.c App/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Barometer" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/IMU" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Memory" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT/src" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT/inc" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Kalman" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Arm_matrix" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Src

clean-App-2f-Src:
	-$(RM) ./App/Src/app_barometer.d ./App/Src/app_barometer.o ./App/Src/app_barometer.su ./App/Src/app_buzzer.d ./App/Src/app_buzzer.o ./App/Src/app_buzzer.su ./App/Src/app_heartbeat.d ./App/Src/app_heartbeat.o ./App/Src/app_heartbeat.su ./App/Src/app_imu.d ./App/Src/app_imu.o ./App/Src/app_imu.su ./App/Src/app_main.d ./App/Src/app_main.o ./App/Src/app_main.su ./App/Src/app_memory.d ./App/Src/app_memory.o ./App/Src/app_memory.su ./App/Src/app_usb.d ./App/Src/app_usb.o ./App/Src/app_usb.su

.PHONY: clean-App-2f-Src

