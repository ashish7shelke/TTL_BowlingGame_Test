// File: Bowling_Game.hpp
#ifndef BOWLING_GAME_HPP
#define BOWLING_GAME_HPP

#include <string>
#include <vector>
#include "Bowling_Roll.hpp"

using namespace std;

class BowlingGame {

public:
    // Constructor to initialize the game with a player name
    BowlingGame();

    // Destructor
    ~BowlingGame();

    // Function to add a roll to the game
    void addRoll(const string pinsCharSequence);
    void addRoll(const std::vector<int>& pinsIntSequence);

    // Function to get the total score of the game
    int getTotalScore() const;

private:
	BowlingRoll **bowlingRolls;
	int numberOfRolls;
	int numberOfFrames;
};

#endif // BOWLING_GAME_HPP
