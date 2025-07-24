#include <iostream>

#include "Bowling_Game.hpp"

using namespace std;

int main(int argc, char* argv[]) {

	string sequence = "";
	BowlingGame *game;

	try {
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

    catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    catch (...) {
        cout << "An unknown error occurred." << endl;
    }

	return 0;
}

//  14456/5/x017/6/x2/6

