################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Barometer/barometer.c 

OBJS += \
./Drivers/Barometer/barometer.o 

C_DEPS += \
./Drivers/Barometer/barometer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Barometer/%.o Drivers/Barometer/%.su: ../Drivers/Barometer/%.c Drivers/Barometer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Barometer" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/IMU" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Memory" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT/src" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT/inc" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Kalman" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Arm_matrix" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Barometer

clean-Drivers-2f-Barometer:
	-$(RM) ./Drivers/Barometer/barometer.d ./Drivers/Barometer/barometer.o ./Drivers/Barometer/barometer.su

.PHONY: clean-Drivers-2f-Barometer

