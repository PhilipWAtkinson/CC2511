################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd3.c \
../Generated_Code/BitIoLdd4.c \
../Generated_Code/Cpu.c \
../Generated_Code/Input.c \
../Generated_Code/Logic1.c \
../Generated_Code/Logic2.c \
../Generated_Code/Logic3.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Vectors.c 

OBJS += \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd3.o \
./Generated_Code/BitIoLdd4.o \
./Generated_Code/Cpu.o \
./Generated_Code/Input.o \
./Generated_Code/Logic1.o \
./Generated_Code/Logic2.o \
./Generated_Code/Logic3.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Vectors.o 

C_DEPS += \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd3.d \
./Generated_Code/BitIoLdd4.d \
./Generated_Code/Cpu.d \
./Generated_Code/Input.d \
./Generated_Code/Logic1.d \
./Generated_Code/Logic2.d \
./Generated_Code/Logic3.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Vectors.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Philip/workspace.kds/Assignment 1/Static_Code/PDD" -I"C:/Users/Philip/workspace.kds/Assignment 1/Static_Code/IO_Map" -I"C:/Users/Philip/workspace.kds/Assignment 1/Sources" -I"C:/Users/Philip/workspace.kds/Assignment 1/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


