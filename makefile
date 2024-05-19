################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include COTS/MCAL/timer/subdir.mk
-include COTS/MCAL/WDT/subdir.mk
-include COTS/MCAL/USART/subdir.mk
-include COTS/MCAL/TWI/subdir.mk
-include COTS/MCAL/TIMER1/subdir.mk
-include COTS/MCAL/TIMER0/subdir.mk
-include COTS/MCAL/SPI/subdir.mk
-include COTS/MCAL/ICU/subdir.mk
-include COTS/MCAL/GIE/subdir.mk
-include COTS/MCAL/EXTI/subdir.mk
-include COTS/MCAL/DIO/subdir.mk
-include COTS/MCAL/ADC/subdir.mk
-include COTS/HAL/LCD/subdir.mk
-include COTS/HAL/KPD/subdir.mk
-include COTS/HAL/AT24C08/subdir.mk
-include COTS/APP/subdir.mk
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
Final_Project.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Final_Project.elf secondary-outputs

# Tool invocations
Final_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Final_Project.map -mmcu=atmega32 -o "Final_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Final_Project.lss: Final_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Final_Project.elf  >"Final_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Final_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Final_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Final_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
