#include <stdio.h>
#include <stdbool.h>
#include "get_random.h"
#include "io_functions.h"

static int MAX_VALUES[3];

void initGame();
void startRound();
void startGuessing(int max, int target);

int main()
{
    initGame();
    greetings();

    while (1)
    {
        startRound();

        if (!askToRepeat()) {
            printGoodBye();
            return 0;
        }
    }    
}

void initGame() {
    MAX_VALUES[0] = 10;
    MAX_VALUES[1] = 100;
    MAX_VALUES[2] = 10000;
    init_random();
    clearScreen();
}

void startRound() {
    clearScreen();
    printDifficultyOptions();

    int difficulty = readDifficulty();
    int max = MAX_VALUES[difficulty - 1];
    int target = get_random(max);

    printDifficulty(difficulty, max);
    startGuessing(max, target);
}

void startGuessing(int max, int target) {
    int guess = 0;
    int counter = 0;

    do {
        guess = readNextGuess(max);
        printGuessFailure(guess, target);
        counter++;
    } while (guess != target);

    printSuccess(counter);
}



