#
# Auto-Generated file. Do not edit!
#

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/I2C/i2c.c

OBJS += \
./src/I2C/i2c.o

C_DEPS += \
./src/I2C/i2c.d

# Each subdirectory must supply rules for building sources it contributes
src/I2C/%.o: ../src/I2C/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: SDE Lite C Compiler'
	D:/LoongIDE/mips-2011.03/bin/mips-sde-elf-gcc.exe -mips32 -G0 -EL -msoft-float -DLS1B -DOS_NONE  -O0 -g -Wall -c -fmessage-length=0 -pipe -I"../" -I"../include" -I"../core/include" -I"../core/mips" -I"../ls1x-drv/include" -I"D:/LoongIDE/Workspace/demo2/src/LED" -I"D:/LoongIDE/Workspace/demo2/src/KEYS" -I"D:/LoongIDE/Workspace/demo2/src/BEPP" -I"D:/LoongIDE/Workspace/demo2/src/I2C" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

