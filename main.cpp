#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void startGame() {
    srand(time(0));
    int hintCount = 1;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    cout << "U can get a hint by entering 0" << endl;


    int chances = 0;
    cout << "Please select the difficulty level:" << endl;
    cout << "1. Easy (10 chances)" << endl;
    cout << "2. Medium (5 chances)" << endl;
    cout << "3. Hard (3 chances)" << endl;

    int difficulty;
    cout << "Choose the difficulty(1|2|3)" << endl;
    cin >> difficulty;
    if (difficulty == 1) chances = 10;
    else if (difficulty == 2) chances = 5;
    else if (difficulty == 3) {
        chances = 3;
        hintCount = 0;
    } else {
        chances = 5;
        cout << "Invalid choice, defaulting to Medium difficulty (5 chances)." << endl;
    }


    int num = rand() % 100 + 1;

    cout << "Great you have selected the " << (chances == 10 ? "Easy" : (chances == 5 ? "Medium" : "Hard")) << " difficulty level." << endl;
    cout << "Let's start!!!" << endl;




    int guess;
    int attempts = 0;


    while (attempts < chances) {
        cout << "Enter your guess (Attempt " << attempts + 1 << "/" << chances << "): ";
        cin >> guess;

        if (guess > 100 || guess < 0) {
            cout << "Invalid number! Try again!" << endl;
            continue;
        }

        attempts++;

        // hint case
        if (guess == 0) {
            if (hintCount) {
                int hintNum;
                int x = rand() % 2;
                if (num < 10) {
                    cout<< "guess is ONE DIGIT"<<endl;
                }
                else {
                    if (x) hintNum = num % 10;
                    else hintNum = num / 10;
                    hintCount--;
                    cout << "Guess contains figure = " << hintNum << endl;
                }
            } else
                cout << "No hints left :( " << endl;
            attempts--;
        } else if (guess < num) {
            cout << "Incorrect! The number is greater than your guess" << endl;
        } else if (guess > num) {
            cout << "Incorrect! The number is less than your guess" << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in "
                 << attempts << " attempts." << endl;
            return;
        }
    }

    cout << "Sorry, you've run out of chances. The correct number was " << num << "." << endl;
}




int main() {
    startGame();
    return 0;
}
