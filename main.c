#include <stdio.h>
#include <stdbool.h>
#include "get_random.h"
#include "io_functions.h"

static int MAX_VALUES[3];

void startRound();
void startGuessing(int max, int target);

int main()
{
    MAX_VALUES[0] = 10;
    MAX_VALUES[1] = 100;
    MAX_VALUES[2] = 10000;

    init_random();
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

void startRound() {
    int difficulty = getDifficulty();
    int max = MAX_VALUES[difficulty - 1];
    int target = get_random(max);

    printDifficulty(difficulty, max);
    startGuessing(max, target);
}

void startGuessing(int max, int target) {
    int guess = 0;
    int counter = 0;

    do {
        guess = readNextInt(max);
        counter++;

        if (guess < target) {
            printf("Ennel nagyobbra gondoltam.\n");
        }
        if (guess > target) {
            printf("Ennel kisebbre gondoltam.\n");
        }
    } while (guess != target);

    printSuccess(counter);
}



