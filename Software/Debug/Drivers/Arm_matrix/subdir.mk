################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Arm_matrix/arm_mat_add_f32.c \
../Drivers/Arm_matrix/arm_mat_cmplx_mult_f32.c \
../Drivers/Arm_matrix/arm_mat_init_f32.c \
../Drivers/Arm_matrix/arm_mat_inverse_f32.c \
../Drivers/Arm_matrix/arm_mat_mult_f32.c \
../Drivers/Arm_matrix/arm_mat_scale_f32.c \
../Drivers/Arm_matrix/arm_mat_sub_f32.c \
../Drivers/Arm_matrix/arm_mat_trans_f32.c 

OBJS += \
./Drivers/Arm_matrix/arm_mat_add_f32.o \
./Drivers/Arm_matrix/arm_mat_cmplx_mult_f32.o \
./Drivers/Arm_matrix/arm_mat_init_f32.o \
./Drivers/Arm_matrix/arm_mat_inverse_f32.o \
./Drivers/Arm_matrix/arm_mat_mult_f32.o \
./Drivers/Arm_matrix/arm_mat_scale_f32.o \
./Drivers/Arm_matrix/arm_mat_sub_f32.o \
./Drivers/Arm_matrix/arm_mat_trans_f32.o 

C_DEPS += \
./Drivers/Arm_matrix/arm_mat_add_f32.d \
./Drivers/Arm_matrix/arm_mat_cmplx_mult_f32.d \
./Drivers/Arm_matrix/arm_mat_init_f32.d \
./Drivers/Arm_matrix/arm_mat_inverse_f32.d \
./Drivers/Arm_matrix/arm_mat_mult_f32.d \
./Drivers/Arm_matrix/arm_mat_scale_f32.d \
./Drivers/Arm_matrix/arm_mat_sub_f32.d \
./Drivers/Arm_matrix/arm_mat_trans_f32.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Arm_matrix/%.o Drivers/Arm_matrix/%.su: ../Drivers/Arm_matrix/%.c Drivers/Arm_matrix/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"F:/Workspace/mini-rockets/Software/App/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"F:/Workspace/mini-rockets/Software/Drivers/Barometer" -I"F:/Workspace/mini-rockets/Software/Drivers/IMU" -I"F:/Workspace/mini-rockets/Software/Drivers/Memory" -I"F:/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT" -I"F:/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT/src" -I"F:/Workspace/mini-rockets/Software/Drivers/RTT/SEGGER_RTT_V756b/RTT/inc" -I"F:/Workspace/mini-rockets/Software/Drivers/RTT" -I"F:/Workspace/mini-rockets/Software/Drivers/Kalman" -I"F:/Workspace/mini-rockets/Software/Drivers/Arm_matrix" -I"F:/Workspace/mini-rockets/Software/Drivers/Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Arm_matrix

clean-Drivers-2f-Arm_matrix:
	-$(RM) ./Drivers/Arm_matrix/arm_mat_add_f32.d ./Drivers/Arm_matrix/arm_mat_add_f32.o ./Drivers/Arm_matrix/arm_mat_add_f32.su ./Drivers/Arm_matrix/arm_mat_cmplx_mult_f32.d ./Drivers/Arm_matrix/arm_mat_cmplx_mult_f32.o ./Drivers/Arm_matrix/arm_mat_cmplx_mult_f32.su ./Drivers/Arm_matrix/arm_mat_init_f32.d ./Drivers/Arm_matrix/arm_mat_init_f32.o ./Drivers/Arm_matrix/arm_mat_init_f32.su ./Drivers/Arm_matrix/arm_mat_inverse_f32.d ./Drivers/Arm_matrix/arm_mat_inverse_f32.o ./Drivers/Arm_matrix/arm_mat_inverse_f32.su ./Drivers/Arm_matrix/arm_mat_mult_f32.d ./Drivers/Arm_matrix/arm_mat_mult_f32.o ./Drivers/Arm_matrix/arm_mat_mult_f32.su ./Drivers/Arm_matrix/arm_mat_scale_f32.d ./Drivers/Arm_matrix/arm_mat_scale_f32.o ./Drivers/Arm_matrix/arm_mat_scale_f32.su ./Drivers/Arm_matrix/arm_mat_sub_f32.d ./Drivers/Arm_matrix/arm_mat_sub_f32.o ./Drivers/Arm_matrix/arm_mat_sub_f32.su ./Drivers/Arm_matrix/arm_mat_trans_f32.d ./Drivers/Arm_matrix/arm_mat_trans_f32.o ./Drivers/Arm_matrix/arm_mat_trans_f32.su

.PHONY: clean-Drivers-2f-Arm_matrix

