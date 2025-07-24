#include "Bowling_Roll.hpp"

BowlingRoll::BowlingRoll(char pinsChar, int frameNumber)
    : pinsChar(pinsChar), frame(frameNumber), nextRoll(nullptr), previousRoll(nullptr) 
    {
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

	if (pinsChar == 'X' || pinsChar == 'x')
		return 10; // + previousRoll->getNumberOfPins() + nextRoll->nextRoll->getNumberOfPins(); // Strike case, add previous and next roll pins
	else if (pinsChar == '/')
		return 10 - previousRoll->getNumberOfPins(); // Spare case, add previous and next roll pins
	else
		return pinsChar - '0';
}

bool BowlingRoll::isStrike() const {
    return (pinsChar == 'X' || pinsChar == 'x');
}
bool BowlingRoll::isSpare() const {
    return (pinsChar == '/');
}


