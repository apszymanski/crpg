CCFLAGS := -std=c++20 -g -Wall -Werror -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic
CXX = g++ $(CCFLAGS)

PROJECT := $(realpath $(CURDIR))
SOURCE :=  $(PROJECT)/src/
BUILD := $(PROJECT)/build/
TEST := $(PROJECT)/test/

Dice.o: $(SOURCE)Dice/Dice.h
	$(CXX) -o $(BUILD)Dice/$@ -c $(SOURCE)Dice/Dice.cpp

testDice: Dice.o
	$(CXX) -o $(TEST)Dice/$@ $(BUILD)Dice/Dice.o $(SOURCE)/Dice/test.cpp

clean :
	rm -f build/Dice/Dice.o test/Dice/testDice
