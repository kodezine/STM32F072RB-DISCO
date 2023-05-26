################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RS485Checker_demo/RS485Checker_demo.c 

OBJS += \
./RS485Checker_demo/RS485Checker_demo.o 

C_DEPS += \
./RS485Checker_demo/RS485Checker_demo.d 


# Each subdirectory must supply rules for building sources it contributes
RS485Checker_demo/%.o RS485Checker_demo/%.su RS485Checker_demo/%.cyclo: ../RS485Checker_demo/%.c RS485Checker_demo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I/Users/sohal/STM32Cube/Repository/STM32Cube_FW_F0_V1.11.4/Drivers/STM32F0xx_HAL_Driver/Inc -I/Users/sohal/STM32Cube/Repository/STM32Cube_FW_F0_V1.11.4/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I/Users/sohal/STM32Cube/Repository/STM32Cube_FW_F0_V1.11.4/Drivers/CMSIS/Device/ST/STM32F0xx/Include -I/Users/sohal/STM32Cube/Repository/STM32Cube_FW_F0_V1.11.4/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-RS485Checker_demo

clean-RS485Checker_demo:
	-$(RM) ./RS485Checker_demo/RS485Checker_demo.cyclo ./RS485Checker_demo/RS485Checker_demo.d ./RS485Checker_demo/RS485Checker_demo.o ./RS485Checker_demo/RS485Checker_demo.su

.PHONY: clean-RS485Checker_demo

