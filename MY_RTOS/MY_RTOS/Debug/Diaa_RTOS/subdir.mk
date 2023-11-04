################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Diaa_RTOS/FIFO_stack.c \
../Diaa_RTOS/OS_porting.c \
../Diaa_RTOS/scheduler.c 

OBJS += \
./Diaa_RTOS/FIFO_stack.o \
./Diaa_RTOS/OS_porting.o \
./Diaa_RTOS/scheduler.o 

C_DEPS += \
./Diaa_RTOS/FIFO_stack.d \
./Diaa_RTOS/OS_porting.d \
./Diaa_RTOS/scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
Diaa_RTOS/%.o Diaa_RTOS/%.su Diaa_RTOS/%.cyclo: ../Diaa_RTOS/%.c Diaa_RTOS/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"I:/Arm Architecture Tests/session1/MY_OS/CMSIS_Driver" -I"I:/Arm Architecture Tests/session1/MY_OS/Diaa_RTOS/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Diaa_RTOS

clean-Diaa_RTOS:
	-$(RM) ./Diaa_RTOS/FIFO_stack.cyclo ./Diaa_RTOS/FIFO_stack.d ./Diaa_RTOS/FIFO_stack.o ./Diaa_RTOS/FIFO_stack.su ./Diaa_RTOS/OS_porting.cyclo ./Diaa_RTOS/OS_porting.d ./Diaa_RTOS/OS_porting.o ./Diaa_RTOS/OS_porting.su ./Diaa_RTOS/scheduler.cyclo ./Diaa_RTOS/scheduler.d ./Diaa_RTOS/scheduler.o ./Diaa_RTOS/scheduler.su

.PHONY: clean-Diaa_RTOS

