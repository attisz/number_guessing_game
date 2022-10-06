#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "get_random.h"

void init_random() {
   srand(time(NULL));
}

int get_random(int max)
{
   return rand() % (max) + 1;
}