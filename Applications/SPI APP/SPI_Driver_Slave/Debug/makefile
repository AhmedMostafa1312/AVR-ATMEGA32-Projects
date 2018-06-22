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
SPI_Driver_Slave.lss \

FLASH_IMAGE += \
SPI_Driver_Slave.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: SPI_Driver_Slave.elf secondary-outputs

# Tool invocations
SPI_Driver_Slave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_Driver_Slave.map -mmcu=atmega16 -o "SPI_Driver_Slave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_Driver_Slave.lss: SPI_Driver_Slave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_Driver_Slave.elf  >"SPI_Driver_Slave.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_Driver_Slave.hex: SPI_Driver_Slave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_Driver_Slave.elf  "SPI_Driver_Slave.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_Driver_Slave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 SPI_Driver_Slave.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: SPI_Driver_Slave.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm16 -cstk500v2 -Uflash:w:SPI_Driver_Slave.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_Driver_Slave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
