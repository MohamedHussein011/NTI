################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AUTOSAR_Test.lss \

FLASH_IMAGE += \
AUTOSAR_Test.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AUTOSAR_Test.elf secondary-outputs

# Tool invocations
AUTOSAR_Test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AUTOSAR_Test.map -mmcu=atmega32 -o "AUTOSAR_Test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AUTOSAR_Test.lss: AUTOSAR_Test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AUTOSAR_Test.elf  >"AUTOSAR_Test.lss"
	@echo 'Finished building: $@'
	@echo ' '

AUTOSAR_Test.hex: AUTOSAR_Test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AUTOSAR_Test.elf  "AUTOSAR_Test.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AUTOSAR_Test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AUTOSAR_Test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AUTOSAR_Test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
