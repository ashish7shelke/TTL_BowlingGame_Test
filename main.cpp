#include <iostream>
#include <vector>
#include <string>
#include "Bowling_Game.hpp"
using namespace std;

void runProgramIntegerSequence();

int main() {
	runProgramIntegerSequence();	
	return 0;
}

void runProgramIntegerSequence()
{
     std::vector<int> sequence;
    std::string input;

    try
    {
        while (input != "q") {
            std::cout << std::endl << "TTL :: BOWLING GAME" << std::endl << std::endl;
            std::cout << "Press 'n' new sequence, 'd' for default TEST Sequence, 'q' to quit" << std::endl << std::endl;

            sequence.clear();
            input.clear();
            std::getline(std::cin, input);

            if (input == "d") {
                sequence = {1,4,4,5,6,4,5,5,10,0,1,7,3,6,4,10,2,8,6}; // Default sequence for testing
            } else if (input == "q") {
                std::cout << std::endl << "Closing the bowling !!!" << std::endl << std::endl;
                break;
            } else if (input == "n") {
                int frame = 1;
                bool firstRoll = true, tenthFrame = false;
                int prevRoll = 0;
                int rollsInTenth = 1;
                int tenthFirst = 0, tenthSecond = 0;

                while (frame <= 10) {
                    int num;
                    std::cout << "Frame No :: " << frame << "\tEnter roll #" << (!tenthFrame ? (firstRoll ? 1 : 2) : rollsInTenth) << ": ";
                    std::cin >> num;
                    if (num < 0 || num > 10) {
                        std::cout << "Invalid entry: " << num << ". Each roll must be between 0 and 10." << std::endl;
                        continue;
                    }
                    if (frame < 10) {
                        if (firstRoll) {
                            prevRoll = num;
                            sequence.push_back(num);
                            if (num == 10) { // Strike
                                frame++;
                            } else {
                                firstRoll = false;
                            }
                        } else {
                            if (prevRoll + num > 10) {
                                std::cout << "Invalid frame: sum of two rolls in frame " << frame
                                          << " is greater than 10 (" << prevRoll << " + " << num << "). ...RETRY..." << std::endl;
                                continue;
                            }
                            sequence.push_back(num);
                            frame++;
                            firstRoll = true;
                        }
                    } else { // 10th frame logic
                        tenthFrame = true; 
                        sequence.push_back(num);
                        if (rollsInTenth == 1) {
                            tenthFirst = num;
                            firstRoll = false;
                        } else if (rollsInTenth == 2) {
                            tenthSecond = num;
                            if (tenthFirst == 10 || ((tenthFirst + tenthSecond) < 10)) {
                                // Open 10th frame, only two rolls allowed
                                break;
                            }
                        } else if (rollsInTenth == 3) {
                            // Max three rolls in 10th frame
                            tenthFrame = false;
                            break; 
                        }
                        rollsInTenth++;

                    }
                }
            }
            else
            {
                std::cout << std::endl << "Invalid Command : Closing the bowling !!!" << std::endl << std::endl;
                return;
            }

            if (!sequence.empty()) {
                BowlingGame game;
                game.addRoll(sequence);
                std::cout << std::endl << "Your Final score is " << game.getTotalScore() << std::endl << std::endl;
            }

            system("pause");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }
}
