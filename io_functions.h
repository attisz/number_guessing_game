#include <stdbool.h>

void clearScreen();

void greetings();

void printDifficultyOptions();

int readDifficulty();

int readNextGuess(int maxValue);

bool askToRepeat();

void printDifficulty(int difficulty, int maxValue);

void printSuccess(int counter);

void printGoodBye();

void printGuessFailure(int guess, int target);