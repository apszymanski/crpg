C++ = /usr/bin/g++
CFLAGS := -std=c++20 -g -Wall -Wextra -Werror -Wpedantic
PROJECT := $(realpath $(CURDIR))
SOURCE :=  $(PROJECT)/src/
BUILD := $(PROJECT)/build/
TEST := $(PROJECT)/test/

Dice.o: $(SOURCE)Dice/Dice.h
	$(C++) $(CFLAGS) -o $(BUILD)Dice/$@ -c $(SOURCE)Dice/Dice.cpp

testDice: $(BUILD)Dice/Dice.o
	$(C++) $(CFLAGS) -o $(TEST)Dice/$@ $(BUILD)Dice/Dice.o $(SOURCE)/Dice/test.cpp

.PHONY : clean
clean :