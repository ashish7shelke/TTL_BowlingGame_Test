#include <iostream>
#include <vector>
#include "Bowling_Game.hpp"

using namespace std;

int runProgramCharSequence();
int runProgramIntegerSequence();

int main() {

	runProgramIntegerSequence();	

	return 0;
}

int runProgramIntegerSequence()
{
   std::vector<int> sequence;
    BowlingGame *game;
    std::string input;

    try
    {
        while (input != "q") {
            cout << endl << "TTL :: BOWLING GAME" << endl << endl;
            cout << "Enter rolls as space-separated integers (0-10, example: 1 4 4 5 6 0 5 5 10 0 1 7 3 6 10 2 6)" << endl;
            cout << "Press 'n' new sequence, 'd' for default TEST Sequence, 'q' to quit" << endl << endl;

            sequence.clear();
            input.clear();
            std::getline(std::cin, input);

            if (input == "d") {
                sequence = {1,4,4,5,6,0,5,5,10,0,1,7,3,6,4,10,2,8,6}; // Default sequence for testing
            } else if (input == "q") {
                cout << endl << "Closing the bowling !!!" << endl << endl;
                break;
            } else if (input == "n"){
                int frame = 0;
                int rollInFrame = 0;
                int prevRoll = 0;
                bool tenthFrame = false;
                int rollsInTenth = 0;
                while (frame < 10) {
                    int num;
                    cout << "Enter roll #" << (sequence.size() + 1) << ": ";
                    cin >> num;
                    if (num < 0 || num > 10) {
                        cout << "Invalid entry: " << num << ". Each roll must be between 0 and 10." << endl;
                        continue;
                    }
                    // Frame sum validation (except 10th frame)
                    if (frame < 9) {
                        if (rollInFrame == 1) {
                            if (prevRoll + num > 10) {
                                cout << "Invalid frame: sum of two rolls in frame " << (frame + 1)
                                     << " is greater than 10 (" << prevRoll << " + " << num << "). ...RETRY..." << endl;
                                continue;
                            }
                        }
                        if (num == 10 && rollInFrame == 0) { // Strike
                            sequence.push_back(num);
                            frame++;
                            rollInFrame = 0;
                            continue;
                        } else if (rollInFrame == 0) {
                            prevRoll = num;
                            rollInFrame = 1;
                        } else {
                            rollInFrame = 0;
                            frame++;
                        }
                    } else { // 10th frame logic
                        if (!tenthFrame) {
                            tenthFrame = true;
                            rollsInTenth = 1;
							cout << "10th frame initializd " << endl;
						} else {
							rollsInTenth++;
						}
                        // Allow up to 3 rolls in 10th frame if strike or spare

                        if ((rollsInTenth == 2) && ( (sequence[sequence.size()-1] == 10)  || (sequence[sequence.size()-1] + num != 10) ) ) {
                            // Open frame, only 2 rolls
                            sequence.push_back(num);
                            break;
                        }
                        if (rollsInTenth == 3) {
                            sequence.push_back(num);
                            break;
                        }
                    }
                    sequence.push_back(num);
                }
            }
			else
			{
				cout << endl << "Invalid Command : Closing the bowling !!!" << endl << endl;
			}

            if (!sequence.empty()) {
                game = new BowlingGame();

                if(nullptr == game) {
                    cout << "Memory allocation failed for BowlingGame." << endl;
                    return 1;
                }

                game->addRoll(sequence); // You need to implement this overload

                cout << endl << "Your Final score is " << game->getTotalScore() << endl << endl;

                delete game;
            }

            system("pause");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;	
}	
//  14456/5/x017/6/x2/6



int runProgramCharSequence()
{

	string sequence = "";
	BowlingGame *game;
try
	{
	while (sequence != "q") {

		cout << endl << "TTL :: BOWLING GAME" << endl << endl;
		cout << "Enter rolls sequence: 'X' - Strike and '/' - Spare (example: '-/X123456789' ) \n\n 'd' for default TEST Sequence \t, 'q' to quit)" << endl << endl;

		sequence.clear();
		cin >> sequence;

		if(sequence == "d")
			sequence = "14456/5/x017/6/x2/6"; // Default sequence for testing

		if (sequence != "q" ) {

			game = new BowlingGame();

			if(nullptr == game) {
				cout << "Memory allocation failed for BowlingGame." << endl;
				return 1; // Exit if memory allocation fails
			}

			game->addRoll(sequence);

			cout << endl << "Your Final score is " << game->getTotalScore() << endl << endl;

			delete game;
		}
		else
			cout << endl << "Closing the bowling !!!" << endl << endl;             


		system("pause");
	}
	}
catch (const std::exception& e) {
		std::cerr << "Exception occurred: " << e.what() << std::endl;
		return 1; // Exit if an exception occurs
	}
}

