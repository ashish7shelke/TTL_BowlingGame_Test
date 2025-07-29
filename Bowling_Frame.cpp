#include "Bowling_Frame.hpp"
#include <iostream>
#include <stdexcept>

BowlingFrame::BowlingFrame(int frameNumber, int firstPins, int secondPins, int thirdPins,
                           std::shared_ptr<BowlingFrame> prev, std::shared_ptr<BowlingFrame> next)
    : frameIndex(frameNumber),
      firstRollPins(firstPins),
      secondRollPins(secondPins),
      thirdRollPins(thirdPins),
      prevFrame(prev),
      nextFrame(next),
      frameScore(0),
      isFrameSpareFlag(false),
      isFrameStrikeFlag(false),
      hasThirdRoll(false)
{
    setFirstPins(firstPins);
    setSecondPins(secondPins);
    if (frameIndex == 10 && (isFrameStrike() || isFrameSpare())) {
        setThirdRollPins(thirdPins);
    }
}

BowlingFrame::~BowlingFrame() = default;

int BowlingFrame::getFrameScore() const {
        if (frameIndex == 10) {
            int score = firstRollPins + secondRollPins;
            if (hasThirdRoll) score += thirdRollPins;
            return score;
        }

        // Strike: 10 + next two rolls
        if (isFrameStrike()) {
            int score = 10;
            BowlingFrame* next = getNextFrame();
            if (next) {
                score += next->getFirstPins();
                if (next->isFrameStrike() && next->getNextFrame()) {
                    score += next->getNextFrame()->getFirstPins();
                } else {
                    score += next->getSecondPins();
                }
            }
            return score;
        }

        // Spare: 10 + next one roll
        if (isFrameSpare()) {
            int score = 10;
            BowlingFrame* next = getNextFrame();
            if (next) {
                score += next->getFirstPins();
            }
            return score;
        }

        // Open frame: just sum
        return firstRollPins + secondRollPins;
}

int BowlingFrame::getFrameIndex() const {
    return frameIndex;
}

BowlingFrame* BowlingFrame::getNextFrame() const {
    return nextFrame ? nextFrame.get() : nullptr;
}

BowlingFrame* BowlingFrame::getPreviousFrame() const {
    return prevFrame ? prevFrame.get() : nullptr;
}

void BowlingFrame::setFirstPins(int pins) {
    firstRollPins = pins;
    isFrameStrikeFlag = (pins == 10);
    // If strike, second roll is 0 unless 10th frame
    if (isFrameStrikeFlag && frameIndex != 10) {
        secondRollPins = 0;
    }
}

void BowlingFrame::setSecondPins(int pins) {
    secondRollPins = pins;
    isFrameSpareFlag = ((firstRollPins + secondRollPins == 10) && firstRollPins != 10);
}

int BowlingFrame::getFirstPins() const {
    return firstRollPins;
}

int BowlingFrame::getSecondPins() const {
    return secondRollPins;
}

void BowlingFrame::setPrevFrame(std::shared_ptr<BowlingFrame> prev) {
    prevFrame = prev;
}

void BowlingFrame::setNextFrame(std::shared_ptr<BowlingFrame> next) {
    nextFrame = next;
}

bool BowlingFrame::isFrameStrike() const {
    return isFrameStrikeFlag;
}

bool BowlingFrame::isFrameSpare() const {
    return isFrameSpareFlag;
}

bool BowlingFrame::isThirdRollAllowed() const {
    return (frameIndex == 10) && (isFrameStrikeFlag || isFrameSpareFlag);
}

void BowlingFrame::setThirdRollPins(int pins) {
    if (isThirdRollAllowed()) {
        thirdRollPins = pins;
        hasThirdRoll = true;
    } else {
        thirdRollPins = 0;
        hasThirdRoll = false;
    }
}

int BowlingFrame::getThirdRollPins() const {
    return hasThirdRoll ? thirdRollPins : 0;
}

int BowlingFrame::getNumberOfPins() const {
    int total = firstRollPins + secondRollPins;
    if (hasThirdRoll) total += thirdRollPins;
    return total;
}

void BowlingFrame::setFrameLevelScore()
{
    frameLevelScore = prevFrame->getFrameScore() + this->getFrameScore();
}

int BowlingFrame::getFrameLevelScore() const
{
    return frameLevelScore; 
}
