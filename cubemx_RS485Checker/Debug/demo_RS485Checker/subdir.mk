################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../demo_RS485Checker/RS485Checker.c 

OBJS += \
./demo_RS485Checker/RS485Checker.o 

C_DEPS += \
./demo_RS485Checker/RS485Checker.d 


# Each subdirectory must supply rules for building sources it contributes
demo_RS485Checker/%.o demo_RS485Checker/%.su demo_RS485Checker/%.cyclo: ../demo_RS485Checker/%.c demo_RS485Checker/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I/Users/sohal/STM32Cube/Repository/STM32Cube_FW_F0_V1.11.4/Drivers/STM32F0xx_HAL_Driver/Inc -I/Users/sohal/STM32Cube/Repository/STM32Cube_FW_F0_V1.11.4/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I/Users/sohal/STM32Cube/Repository/STM32Cube_FW_F0_V1.11.4/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/Users/sohal/STM32Cube/Repository/STM32Cube_FW_F0_V1.11.4/Drivers/CMSIS/Include -I"/Users/sohal/GitHub/STM32F072RB-DISCO/cubeide_RS485Checker/demo_RS485Checker" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-demo_RS485Checker

clean-demo_RS485Checker:
	-$(RM) ./demo_RS485Checker/RS485Checker.cyclo ./demo_RS485Checker/RS485Checker.d ./demo_RS485Checker/RS485Checker.o ./demo_RS485Checker/RS485Checker.su

.PHONY: clean-demo_RS485Checker

