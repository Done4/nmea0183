################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/base.cpp \
../src/gga.cpp \
../src/gll.cpp \
../src/gsa.cpp \
../src/gsv.cpp \
../src/main.cpp \
../src/rmc.cpp \
../src/util.cpp \
../src/vtg.cpp 

OBJS += \
./src/base.o \
./src/gga.o \
./src/gll.o \
./src/gsa.o \
./src/gsv.o \
./src/main.o \
./src/rmc.o \
./src/util.o \
./src/vtg.o 

CPP_DEPS += \
./src/base.d \
./src/gga.d \
./src/gll.d \
./src/gsa.d \
./src/gsv.d \
./src/main.d \
./src/rmc.d \
./src/util.d \
./src/vtg.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/bnkj/worspace/0183demo/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


