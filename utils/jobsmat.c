//
// Created by sreejan patel on 07/10/21.
//

#include "jobsmat.h"

void make_jobs_mat(){
    jobs_list **p;
    p = (jobs_list **)malloc(sizeof(jobs_list *)* MAX_TOKENS);
    for(int i = 0 ; i < MAX_TOKENS ; i++){
        p[i] = malloc(sizeof(jobs_list));
    }
    jobs = p;
}