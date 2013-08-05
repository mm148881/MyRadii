################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InputRadii.cpp \
../src/Myradius.cpp \
../src/RadiiDBase.cpp \
../src/main.cpp 

OBJS += \
./src/InputRadii.o \
./src/Myradius.o \
./src/RadiiDBase.o \
./src/main.o 

CPP_DEPS += \
./src/InputRadii.d \
./src/Myradius.d \
./src/RadiiDBase.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


