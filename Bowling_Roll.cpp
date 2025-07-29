#include "Bowling_Roll.hpp"
#include <iostream>

BowlingRoll::BowlingRoll(const char pins, int frameNumber, BowlingRoll* prev, BowlingRoll* next)
    : pinsChar(pins), frame(frameNumber), previousRoll(prev), nextRoll(next), pinsInt(0)
{
	// Initialize the score based on the character provided
	if (pinsChar == 'X' || pinsChar == 'x') {
		pinsInt = 10; // Strike
		setFrameComplete(true);
	} else if (pinsChar == '/') {
		pinsInt = -1; // Spare, will be calculated later
		setFrameComplete(true);
	} else if (pinsChar >= '0' && pinsChar <= '9') {
		pinsInt = pinsChar - '0'; // Convert character to intege
    }

	// validate the pin count
	if (pinsInt < -1 || pinsInt > 10) {
		throw std::invalid_argument("Invalid character pin count for BowlingRoll");
	}
}

BowlingRoll::BowlingRoll(int pinsIntFrame, int frameNumber, BowlingRoll* prev, BowlingRoll* next)
	: pinsInt(pinsIntFrame), frame(frameNumber),
	  nextRoll(prev), previousRoll(next) 
{
	// Initialize the scores based on the integer values provided
	if (pinsInt < 0 || pinsInt > 10) {
		throw std::invalid_argument("Invalid integer pin count for BowlingRoll");
	}
}

BowlingRoll::~BowlingRoll() {
    nextRoll = nullptr;
    previousRoll = nullptr;
}

int BowlingRoll::getScore() const {
	int score = getNumberOfPins();
	if (nextRoll && frame < 9 && (isSpare() || isStrike())) {
        
		score +=  nextRoll->getNumberOfPins();   // Add the score of the next roll - For Spare

		if (isStrike() && nextRoll->getNextRoll()) // for strike
			score += nextRoll->getNextRoll()->getNumberOfPins(); // Add the score of the roll after the next roll if it's a strike
	}

	return score;
}

int BowlingRoll::getFrame() const {
    return frame;
}

BowlingRoll* BowlingRoll::getNextRoll() const {
    return nextRoll;
}

BowlingRoll* BowlingRoll::getPreviousRoll() const {
    return previousRoll;
}

void BowlingRoll::setNextRoll(BowlingRoll* next) {
    nextRoll = next;
}

void BowlingRoll::setPreviousRoll(BowlingRoll* previous) {
    previousRoll = previous;
}

int BowlingRoll::getNumberOfPins() const {
	if(pinsInt == -1) {
		const_cast<BowlingRoll*>(this)->pinsInt = 10 - (previousRoll ? previousRoll->getNumberOfPins() : 0); // Calculate spare
	}
	return pinsInt; // Return the integer value of the pins knocked down
}

bool BowlingRoll::isStrike() const {
    //return (pinsChar == 'X' || pinsChar == 'x');
	//if(isFrameComplete)
		return (getNumberOfPins() == 10); // A strike is when all 10 pins are knocked down in the first roll
	
	// return false; // If the frame is complete, it cannot be a strike
}

bool BowlingRoll::isSpare() const {
    //return (pinsChar == '/');
	if(previousRoll && getIfFrameComplete() && !isStrike())
		return (getNumberOfPins() + previousRoll->getNumberOfPins() == 10); // A spare is when all 10 pins are knocked down in the second roll of a frame
	else
		return false; // If there is no previous roll, it cannot be a spare 
}

void BowlingRoll::setFrameComplete(bool complete) {
	isFrameComplete = complete;
}
