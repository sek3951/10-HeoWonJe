#include <cstdlib>
#include <time.h>
#include "common.h"

void Shuffle(int *deck){
        for(int i = 1; i <= 52; i++)
                deck[i-1] = i;
        int tmp1;
        for(int i = 0; i < 52; i++){
                srand(time(NULL));
                int random = rand() % 52;
                tmp1 = deck[i];
                deck[i] = deck[random];
                deck[random] = tmp1;
        }
}

