CCFLAGS := -std=c++20 -g -Wall -Werror -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic
CXX = g++ $(CCFLAGS)

PROJECT := $(realpath $(CURDIR))
SOURCE :=  $(PROJECT)/src/
BUILD := $(PROJECT)/build/
TEST := $(PROJECT)/test/

Dice.o: $(SOURCE)Dice/Dice.h
	$(CXX) -o $(BUILD)Dice/$@ -c $(SOURCE)Dice/Dice.cpp

testDice: Dice.o
	$(CXX) -o $(TEST)Dice/$@ $(BUILD)Dice/Dice.o $(SOURCE)Dice/test.cpp

Abilities.o: $(SOURCE)Abilities/Abilities.h
	$(CXX) -o $(BUILD)Abilities/$@ -c $(SOURCE)Abilities/Abilities.cpp

testAbilities: Abilities.o
	$(CXX) -o $(TEST)Abilities/$@ $(BUILD)Abilities/Abilities.o $(SOURCE)Abilities/test.cpp

clean :
	rm -f $(BUILD)/Dice/Dice.o $(TEST)/Dice/testDice $(BUILD)/Abilities/Abilities.o $(TEST)/Abilities/testAbilities
