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
IMT_Projectt.lss \

FLASH_IMAGE += \
IMT_Projectt.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: IMT_Projectt.elf secondary-outputs

# Tool invocations
IMT_Projectt.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,IMT_Projectt.map -mmcu=atmega32 -o "IMT_Projectt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

IMT_Projectt.lss: IMT_Projectt.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S IMT_Projectt.elf  >"IMT_Projectt.lss"
	@echo 'Finished building: $@'
	@echo ' '

IMT_Projectt.hex: IMT_Projectt.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex IMT_Projectt.elf  "IMT_Projectt.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: IMT_Projectt.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 IMT_Projectt.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: IMT_Projectt.elf
	@echo 'Invoking: AVRDude'
	F:\Embedded System\Tools\SDK\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -u -Uflash:w:IMT_Projectt.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) IMT_Projectt.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
