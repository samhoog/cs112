################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ArrayQueueTester.cpp \
../LinkedQueue.cpp \
../LinkedQueueTester.cpp \
../Palindrome.cpp \
../PalindromeTester.cpp \
../tester.cpp 

OBJS += \
./ArrayQueueTester.o \
./LinkedQueue.o \
./LinkedQueueTester.o \
./Palindrome.o \
./PalindromeTester.o \
./tester.o 

CPP_DEPS += \
./ArrayQueueTester.d \
./LinkedQueue.d \
./LinkedQueueTester.d \
./Palindrome.d \
./PalindromeTester.d \
./tester.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


