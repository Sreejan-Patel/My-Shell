#include "bgprocessmat.h"

// creates a array of pointer to struct process , which store the name and pid of the bgprocess

void make_bgprocess_mat(){

    process **p;
    p = (process**)malloc(sizeof(process*)* MAX_TOKENS);
    for(int i = 0 ; i < MAX_TOKENS ; i++){
        p[i] = malloc(sizeof(process));
    }
    run = p;
}