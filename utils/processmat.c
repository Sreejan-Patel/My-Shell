#include "processmat.h"

// creates an array of pointers to struct process , which store the name and pid of the bgprocess
void make_bgprocess_mat(){

    process **p;
    p = (process**)malloc(sizeof(process*)* MAX_TOKENS);
    for(int i = 0 ; i < MAX_TOKENS ; i++){
        p[i] = malloc(sizeof(process));
    }
    run = p;
}

// creates 1 array of pointer to struct process , which store the name and pid of the fgprocess
void make_fgprocess_mat(){
    process **f;
    f = (process**)malloc(sizeof(process*));
    f[0] = malloc(sizeof(process));
    f[0]->pid = -1;
    fg_run = f;
}