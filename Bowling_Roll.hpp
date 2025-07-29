// File: Bowling_Roll.hpp
#ifndef BOWLING_ROLL_HPP
#define BOWLING_ROLL_HPP

#include <stdexcept>

class BowlingRoll {
public:
    // Constructor to initialize the roll with a score
    BowlingRoll(const char pins, int frameNumber, BowlingRoll* prev = nullptr, BowlingRoll* next = nullptr);
    BowlingRoll(int pinsIntFrame, int frameNumber, BowlingRoll* prev = nullptr, BowlingRoll* next = nullptr);

    // Destructor
    ~BowlingRoll();

    // Getter for the score
    int getScore() const;

    // Getter for the frame number
    int getFrame() const;

    // Getter for the next roll
    BowlingRoll* getNextRoll() const;

    // Getter for the previous roll
    BowlingRoll* getPreviousRoll() const;

    // Setter for the next roll
    void setNextRoll(BowlingRoll* next);

    // Setter for the previous roll
    void setPreviousRoll(BowlingRoll* previous);

    // Function to check if the roll is a strike
    bool isStrike() const; // Player knocks down all pins in the first roll of a frame

    // Function to check if the roll is a spare
    bool isSpare() const; // Player knocks down all pins in the second roll of a frame

    void setFrameComplete(bool complete);
    bool getIfFrameComplete() const {
        return isFrameComplete;
    }

private:

    int getNumberOfPins() const;

    BowlingRoll* previousRoll = nullptr; // Pointer to the previous roll in the sequence
    BowlingRoll* nextRoll = nullptr; // Pointer to the next roll in the sequence


    char pinsChar; // The score for this roll
    int pinsInt; // The score for this roll as an integer
    int frame; // The frame in which this roll occurs
    bool isFrameComplete = false; // Flag to indicate if this roll is a spare
};

#endif // BOWLING_ROLL_HPP

