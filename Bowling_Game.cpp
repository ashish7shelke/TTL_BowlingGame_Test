#include <iostream>
#include "Bowling_Game.hpp"

BowlingGame::BowlingGame() 
    : bowlingRolls(nullptr), numberOfRolls(0), numberOfFrames(0) {
}

BowlingGame::~BowlingGame()
{
    // Clean up dynamically allocated BowlingRoll objects
    for (int i = 0; i < numberOfRolls; ++i) {
        if(bowlingRolls[i] != nullptr)
            delete bowlingRolls[i];
    }
    
    // Clean up the array of pointers
    if (bowlingRolls != nullptr)
	delete bowlingRolls;
}

void BowlingGame::addRoll(const string pinsCharSequence) {
	numberOfRolls = pinsCharSequence.length();
	bowlingRolls = new BowlingRoll*[numberOfRolls];
	bool frameEnd = false;

	for (int i = 0; i < numberOfRolls; i++) {

		bowlingRolls[i] = new BowlingRoll(pinsCharSequence[i], numberOfFrames);
        if (nullptr == bowlingRolls[i]) {
            std::cerr << "Memory allocation failed for BowlingRoll at index " << i << "." << std::endl;
            return; // Exit if memory allocation fails
        }

		if (i > 0) {
			bowlingRolls[i - 1]->setNextRoll(bowlingRolls[i]);
			bowlingRolls[i]->setPreviousRoll(bowlingRolls[i - 1]);
		}

		if (bowlingRolls[i]->isStrike()) // X
			frameEnd = true;

		if (frameEnd && numberOfFrames < 9)  
			numberOfFrames++;

        if(frameEnd && numberOfFrames == 9 && bowlingRolls[i]->isSpare())
            frameEnd = false; // To capture additional 10th frame roll in case of spare
        else
            frameEnd = !frameEnd; // Adds 2 rolls
	}
}


int BowlingGame::getTotalScore() const {
    int totalScore = 0;

    for (int i = 0; i < numberOfRolls; ++i) {
        totalScore += bowlingRolls[i]->getScore();

        std::cout << "Roll " << i + 1 << ": " 
                  << bowlingRolls[i]->getScore() 
                  << " (Frame: " << bowlingRolls[i]->getFrame() + 1 << ")" 
                  << " | Total Score: " << totalScore
                  << std::endl;
    }

    return totalScore;
}
