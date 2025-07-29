#ifndef BOWLING_GAME_HPP
#define BOWLING_GAME_HPP

#include <vector>
#include <memory>
#include "Bowling_Frame.hpp"

class BowlingGame {
public:
    BowlingGame();
    ~BowlingGame();

    // Add a sequence of rolls (as integers) to the game
    void addRoll(const std::vector<int>& pinsIntSequence);

    // Get the total score for the game
    int getTotalScore() const;

private:
    std::vector<std::shared_ptr<BowlingFrame>> frames;
    int numberOfFrames;
};

#endif // BOWLING_GAME_HPP