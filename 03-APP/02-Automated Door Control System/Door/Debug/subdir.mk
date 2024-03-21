################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../KEYPAD_program.c \
../LCD_program.c \
../LED_program.c \
../SERVO_program.c \
../TIMER_program.c \
../User_Functions.c \
../main.c 

OBJS += \
./DIO_program.o \
./KEYPAD_program.o \
./LCD_program.o \
./LED_program.o \
./SERVO_program.o \
./TIMER_program.o \
./User_Functions.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./KEYPAD_program.d \
./LCD_program.d \
./LED_program.d \
./SERVO_program.d \
./TIMER_program.d \
./User_Functions.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


