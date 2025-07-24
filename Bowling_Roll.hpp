// File: Bowling_Roll.hpp
#ifndef BOWLING_ROLL_HPP
#define BOWLING_ROLL_HPP

class BowlingRoll {
public:
    // Constructor to initialize the roll with a score
    BowlingRoll(char pinsChar, int frameNumber);

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


private:

    int getNumberOfPins() const;

    BowlingRoll* nextRoll = nullptr; // Pointer to the next roll in the sequence
    BowlingRoll* previousRoll = nullptr; // Pointer to the previous roll in the sequence

    char pinsChar; // The score for this roll
    int frame; // The frame in which this roll occurs
};

#endif // BOWLING_ROLL_HPP

