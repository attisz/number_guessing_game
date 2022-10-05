#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_random() {
   srand(time(NULL));
}

int get_random(int max)
{
   return rand() % (max) + 1;
}