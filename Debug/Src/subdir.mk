################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/freertos.c \
../Src/stm32f0xx_hal_msp.c \
../Src/stm32f0xx_it.c \
../Src/system_stm32f0xx.c 

CPP_SRCS += \
../Src/Message.cpp \
../Src/Mrf24j.cpp \
../Src/main.cpp 

OBJS += \
./Src/Message.o \
./Src/Mrf24j.o \
./Src/freertos.o \
./Src/main.o \
./Src/stm32f0xx_hal_msp.o \
./Src/stm32f0xx_it.o \
./Src/system_stm32f0xx.o 

C_DEPS += \
./Src/freertos.d \
./Src/stm32f0xx_hal_msp.d \
./Src/stm32f0xx_it.d \
./Src/system_stm32f0xx.d 

CPP_DEPS += \
./Src/Message.d \
./Src/Mrf24j.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -std=c++0x '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F031x6 -I"/home/johan/workspace_stm32/zigbee_LED_project/Inc" -I"/home/johan/workspace_stm32/zigbee_LED_project/Drivers/STM32F0xx_HAL_Driver/Inc" -I"/home/johan/workspace_stm32/zigbee_LED_project/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"/home/johan/workspace_stm32/zigbee_LED_project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"/home/johan/workspace_stm32/zigbee_LED_project/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"/home/johan/workspace_stm32/zigbee_LED_project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/johan/workspace_stm32/zigbee_LED_project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/johan/workspace_stm32/zigbee_LED_project/Drivers/CMSIS/Include"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -std=c11 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F031x6 -I"/home/johan/workspace_stm32/zigbee_LED_project/Inc" -I"/home/johan/workspace_stm32/zigbee_LED_project/Drivers/STM32F0xx_HAL_Driver/Inc" -I"/home/johan/workspace_stm32/zigbee_LED_project/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"/home/johan/workspace_stm32/zigbee_LED_project/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"/home/johan/workspace_stm32/zigbee_LED_project/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"/home/johan/workspace_stm32/zigbee_LED_project/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/johan/workspace_stm32/zigbee_LED_project/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/johan/workspace_stm32/zigbee_LED_project/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


