#include <iostream>
#include "Bowling_Game.hpp"

BowlingGame::BowlingGame() 
    : numberOfFrames(0) {
}

BowlingGame::~BowlingGame()
{
}

void BowlingGame::addRoll(const std::vector<int>& pinsIntSequence) {
    frames.clear();
    numberOfFrames = 0;

    std::shared_ptr<BowlingFrame> prevFrame = nullptr;
    size_t i = 0;
    while (numberOfFrames < 10 && i < pinsIntSequence.size()) {
        int first = pinsIntSequence[i++];
        int second = 0;
        int third = 0;

        if (numberOfFrames == 9) { // 10th frame
            if (i < pinsIntSequence.size()) second = pinsIntSequence[i++];
            if ((first == 10 || first + second == 10) && i < pinsIntSequence.size())
                third = pinsIntSequence[i++];
        } else {
            if (first != 10 && i < pinsIntSequence.size())
                second = pinsIntSequence[i++];
        }

        auto frame = std::make_shared<BowlingFrame>(numberOfFrames + 1, first, second, third, prevFrame, nullptr);
        if (prevFrame) prevFrame->setNextFrame(frame);
        frames.push_back(frame);
        prevFrame = frame;
        numberOfFrames++;
    }
}

int BowlingGame::getTotalScore() const {
    int total = 0;
    for (const auto& frame : frames) {
        total += frame->getFrameScore();
        std::cout << "Frame " << frame->getFrameIndex()  /*<< ": "
             << frame->getFirstPins() << ", "
             << frame->getSecondPins() << ", "
             << frame->getThirdRollPins()*/<< " | Score: "
             << total << std::endl;
    }
    return total;
}
