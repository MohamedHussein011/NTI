################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DIO_program.c \
../GI_program.c \
../KEYPAD_program.c \
../LCD_program.c \
../LDR_program.c \
../LED_program.c \
../User_Functions.c \
../main.c 

OBJS += \
./ADC_program.o \
./DIO_program.o \
./GI_program.o \
./KEYPAD_program.o \
./LCD_program.o \
./LDR_program.o \
./LED_program.o \
./User_Functions.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./DIO_program.d \
./GI_program.d \
./KEYPAD_program.d \
./LCD_program.d \
./LDR_program.d \
./LED_program.d \
./User_Functions.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


