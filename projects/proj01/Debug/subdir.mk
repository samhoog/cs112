################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application.cpp \
../PlayList.cpp \
../PlayListTester.cpp \
../Song.cpp \
../SongTester.cpp \
../main.cpp 

OBJS += \
./Application.o \
./PlayList.o \
./PlayListTester.o \
./Song.o \
./SongTester.o \
./main.o 

CPP_DEPS += \
./Application.d \
./PlayList.d \
./PlayListTester.d \
./Song.d \
./SongTester.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


