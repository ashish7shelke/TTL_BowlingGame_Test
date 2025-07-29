#ifndef BOWLING_FRAME_HPP
#define BOWLING_FRAME_HPP

#include <stdexcept>
#include <memory>

class BowlingFrame {
public:
    // Constructor to initialize the frame with scores and links
    BowlingFrame(int frameNumber, int firstPins, int secondPins = 0, int thirdPins = 0,
                 std::shared_ptr<BowlingFrame> prev = nullptr, std::shared_ptr<BowlingFrame> next = nullptr);

    // Destructor
    ~BowlingFrame();

    // Getters
    int getFrameScore() const;
    int getFrameIndex() const;
    BowlingFrame* getNextFrame() const;
    BowlingFrame* getPreviousFrame() const;
    int getFirstPins() const;
    int getSecondPins() const;
    int getThirdRollPins() const;

    // Setters
    void setFirstPins(int pins);
    void setSecondPins(int pins);
    void setThirdRollPins(int pins);
    void setPrevFrame(std::shared_ptr<BowlingFrame> prev);
    void setNextFrame(std::shared_ptr<BowlingFrame> next);

    // Frame state checks
    bool isFrameStrike() const;
    bool isFrameSpare() const;
    bool isThirdRollAllowed() const;

    void setFrameLevelScore();
    int getFrameLevelScore();

private:
    int getNumberOfPins() const;

    int frameIndex;                // The frame number (1-10)
    int firstRollPins;             // Pins knocked down in first roll
    int secondRollPins;            // Pins knocked down in second roll
    int thirdRollPins = 0;         // Pins knocked down in third roll (10th frame only)
    int frameScore;                // Cached frame score
    int frameLevelScore;     
    bool hasThirdRoll = false;     // True if third roll is used (10th frame)
    bool isFrameSpareFlag = false; // True if frame is a spare
    bool isFrameStrikeFlag = false;// True if frame is a strike

    std::shared_ptr<BowlingFrame> prevFrame = nullptr;
    std::shared_ptr<BowlingFrame> nextFrame = nullptr;
};

#endif // BOWLING_FRAME_HPP
