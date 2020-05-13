################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/gpio.cpp \
../src/main.cpp \
../src/pwm.cpp \
../src/socket.cpp 

OBJS += \
./src/gpio.o \
./src/main.o \
./src/pwm.o \
./src/socket.o 

CPP_DEPS += \
./src/gpio.d \
./src/main.d \
./src/pwm.d \
./src/socket.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++0x -I/usr/arm-linux-gnueabihf/include -I/usr/arm-linux-gnueabihf/include/c++/5.4.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


