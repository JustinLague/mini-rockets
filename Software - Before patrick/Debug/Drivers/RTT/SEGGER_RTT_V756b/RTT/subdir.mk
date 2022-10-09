################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../Drivers/RTT/SEGGER_RTT_V756b/RTT/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./Drivers/RTT/SEGGER_RTT_V756b/RTT/SEGGER_RTT_ASM_ARMv7M.o 

S_UPPER_DEPS += \
./Drivers/RTT/SEGGER_RTT_V756b/RTT/SEGGER_RTT_ASM_ARMv7M.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/RTT/SEGGER_RTT_V756b/RTT/%.o: ../Drivers/RTT/SEGGER_RTT_V756b/RTT/%.S Drivers/RTT/SEGGER_RTT_V756b/RTT/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Drivers-2f-RTT-2f-SEGGER_RTT_V756b-2f-RTT

clean-Drivers-2f-RTT-2f-SEGGER_RTT_V756b-2f-RTT:
	-$(RM) ./Drivers/RTT/SEGGER_RTT_V756b/RTT/SEGGER_RTT_ASM_ARMv7M.d ./Drivers/RTT/SEGGER_RTT_V756b/RTT/SEGGER_RTT_ASM_ARMv7M.o

.PHONY: clean-Drivers-2f-RTT-2f-SEGGER_RTT_V756b-2f-RTT

