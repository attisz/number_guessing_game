#include <stdio.h>
#include <stdbool.h>
#include "io_functions.h"

void system(char* s);

void clearScreen() {
    system("clear");
}

void greetings() {
    printf("Udv kedves jatekos! Gondolni fogok egy szamra, neked ki kell talalnod. Kezdhetjuk? <enter>\n");
    getchar();
    return;
}

void printDifficultyOptions() {
    printf("Add meg a nehezsegi szintet!\n");
    printf("1 - konnyu (1-10)\n");
    printf("2 - kozepes (1-100)\n");
    printf("3 - nehez (1-10000)\n");
}

int readDifficulty() {
    int difficulty = 0;
    bool validDifficulty;

    do {
        scanf("%d", &difficulty);
        validDifficulty = 1 <= difficulty && difficulty <= 3;

        if (!validDifficulty) {
            printf("Hiba! A nehezsegi szint 1,2 vagy 3 lehet.\n");
            getchar(); // to swallow trailing end line character
        }
    } while (!validDifficulty);

    return difficulty;
}

int readNextGuess(int maxValue) {
    int input = 0;
    bool valid;

    do {
        scanf("%d", &input);

        valid = 1 <= input && input <= maxValue;

        if (!valid) {
            printf("Tippelj egy szamot 1 es %d kozott.\n", maxValue);
            getchar(); // to swallow trailing end line character
        }
    } while (!valid);

    return input;
}

bool askToRepeat() {
    char c;

    printf("Szeretnel ujra jatszani? (i/n)\n");

    do {
        scanf("%c", &c);
    } while (c != 'i' && c != 'n');

    return c == 'i';
}

void printDifficulty(int difficulty, int maxValue) {
    printf("Valasztott nehezsegi szint: %d.\nGondoltam egy szamra 1 es %d kozott, kezdheted kitalalni!\n", difficulty, maxValue);
}

void printSuccess(int counter) {
    printf("Siker! %d lepesbol talatad ki a szamot. Nem rossz!\n", counter);
}

void printGoodBye() {
    printf("Orultem, hogy egyutt jatszottunk. Viszlat!\n");
}

void printGuessFailure(int guess, int target) {
    if (guess < target) {
        printf("Ennel nagyobbra gondoltam.\n");
    }
    if (guess > target) {
        printf("Ennel kisebbre gondoltam.\n");
    }
}