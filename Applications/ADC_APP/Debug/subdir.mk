################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Cfg.c \
../ADC_Prog.c \
../DIO_Cfg.c \
../DIO_Prog.c \
../Delay.c \
../ExtINT_Prog.c \
../LCD_Prog.c \
../main.c 

OBJS += \
./ADC_Cfg.o \
./ADC_Prog.o \
./DIO_Cfg.o \
./DIO_Prog.o \
./Delay.o \
./ExtINT_Prog.o \
./LCD_Prog.o \
./main.o 

C_DEPS += \
./ADC_Cfg.d \
./ADC_Prog.d \
./DIO_Cfg.d \
./DIO_Prog.d \
./Delay.d \
./ExtINT_Prog.d \
./LCD_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


