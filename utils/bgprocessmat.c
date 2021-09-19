#include "bgprocessmat.h"

void make_bgprocess_mat(){

    process **p;
    p = (process**)malloc(sizeof(process*)* MAX_TOKENS);
    for(int i = 0 ; i < MAX_TOKENS ; i++){
        p[i] = malloc(sizeof(process));
    }
    run = p;
}