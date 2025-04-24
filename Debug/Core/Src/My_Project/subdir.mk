################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/My_Project/DCR_SIGNAL.c \
../Core/Src/My_Project/RISING_PHOTON.c \
../Core/Src/My_Project/USART_PC.c 

OBJS += \
./Core/Src/My_Project/DCR_SIGNAL.o \
./Core/Src/My_Project/RISING_PHOTON.o \
./Core/Src/My_Project/USART_PC.o 

C_DEPS += \
./Core/Src/My_Project/DCR_SIGNAL.d \
./Core/Src/My_Project/RISING_PHOTON.d \
./Core/Src/My_Project/USART_PC.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/My_Project/%.o Core/Src/My_Project/%.su Core/Src/My_Project/%.cyclo: ../Core/Src/My_Project/%.c Core/Src/My_Project/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-My_Project

clean-Core-2f-Src-2f-My_Project:
	-$(RM) ./Core/Src/My_Project/DCR_SIGNAL.cyclo ./Core/Src/My_Project/DCR_SIGNAL.d ./Core/Src/My_Project/DCR_SIGNAL.o ./Core/Src/My_Project/DCR_SIGNAL.su ./Core/Src/My_Project/RISING_PHOTON.cyclo ./Core/Src/My_Project/RISING_PHOTON.d ./Core/Src/My_Project/RISING_PHOTON.o ./Core/Src/My_Project/RISING_PHOTON.su ./Core/Src/My_Project/USART_PC.cyclo ./Core/Src/My_Project/USART_PC.d ./Core/Src/My_Project/USART_PC.o ./Core/Src/My_Project/USART_PC.su

.PHONY: clean-Core-2f-Src-2f-My_Project

