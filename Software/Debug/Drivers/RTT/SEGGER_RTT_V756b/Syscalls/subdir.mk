################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_GCC.c \
../Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_IAR.c \
../Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_KEIL.c \
../Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_SES.c 

OBJS += \
./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_GCC.o \
./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_IAR.o \
./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_KEIL.o \
./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_SES.o 

C_DEPS += \
./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_GCC.d \
./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_IAR.d \
./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_KEIL.d \
./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_SES.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/RTT/SEGGER_RTT_V756b/Syscalls/%.o Drivers/RTT/SEGGER_RTT_V756b/Syscalls/%.su: ../Drivers/RTT/SEGGER_RTT_V756b/Syscalls/%.c Drivers/RTT/SEGGER_RTT_V756b/Syscalls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Barometer" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/IMU" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/Memory" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT/src" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT/inc" -I"C:/Users/user/Desktop/Workspace/mini-rockets/Software/Drivers/RTT" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-RTT-2f-SEGGER_RTT_V756b-2f-Syscalls

clean-Drivers-2f-RTT-2f-SEGGER_RTT_V756b-2f-Syscalls:
	-$(RM) ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_GCC.d ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_GCC.o ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_GCC.su ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_IAR.d ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_IAR.o ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_IAR.su ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_KEIL.d ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_KEIL.o ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_KEIL.su ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_SES.d ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_SES.o ./Drivers/RTT/SEGGER_RTT_V756b/Syscalls/SEGGER_RTT_Syscalls_SES.su

.PHONY: clean-Drivers-2f-RTT-2f-SEGGER_RTT_V756b-2f-Syscalls

