#include "jobs.h"

void command_jobs(token_mat arg){
    if(arg.num_args > 1){
        printf("Error Too many arguments!\n");
        return;
    }
    char **print_jobs;
    print_jobs = (char**) malloc(sizeof(char*)*MAX_TOKENS);
    char **compare_jobs;
    compare_jobs = (char**) malloc(sizeof(char*)*MAX_TOKENS);
    int count = 0;
    for(int i = 0; i < MAX_TOKENS && run[i]->pid != 0; i++){
        print_jobs[i] = (char*) malloc(sizeof(char)*MAX_TOKEN_LENGTH);
        compare_jobs[i] = (char*) malloc(sizeof(char)*MAX_TOKEN_LENGTH);

        char pid[MAX_TOKENS];
        sprintf(pid,"%d",run[i]->pid);

        char final_stat[MAX_TOKENS];
        char *stat = status(pid);
        if (stat == NULL) {
            continue;
        }
        else if (strcmp(stat,"R") == 0) {
            strcpy(final_stat,"Running");
        } else if (strcmp(stat,"S") == 0) {
            strcpy(final_stat,"Running");
        } else if (strcmp(stat,"Z") == 0) {
            strcpy(final_stat,"Zombie");
        } else if (strcmp(stat,"T") == 0) {
            strcpy(final_stat,"Stopped");
        } else {
            perror("Error status ID! ");
            continue;
        }
        if(arg.num_args == 0){
            sprintf(print_jobs[i],"[%d] %s %s [%d]",i+1,final_stat,run[i]->name,run[i]->pid);
            sprintf(compare_jobs[i],"%s",run[i]->name);
            count++;
        }
        else{
            if(strcmp(arg.args[i],"-r") == 0){
                if(strcmp(final_stat,"Running") == 0){
                    sprintf(print_jobs[i],"[%d] %s %s [%d]",i+1,final_stat,run[i]->name,run[i]->pid);
                    sprintf(compare_jobs[i],"%s",run[i]->name);
                    count++;
                }
                else
                    continue;
            }
            else if(strcmp(arg.args[i],"-s") == 0){
                if(strcmp(final_stat,"Stopped") == 0){
                    sprintf(print_jobs[i],"[%d] %s %s [%d]",i+1,final_stat,run[i]->name,run[i]->pid);
                    sprintf(compare_jobs[i],"%s",run[i]->name);
                    count++;
                }
                else
                    continue;
            }
            else{
                printf("Error Wrong Flag\n");
                continue;
            }
        }
    }
    char temp[MAX_TOKEN_LENGTH];
    for(int i = 0 ; i < count ; i++){
        for(int j = i+1 ; j < count ; j++){
            for(int k = 0 ; ; k++){
                if(compare_jobs[i][k] == '\0' || compare_jobs[j][k] == '\0')
                    break;
                if(strcmp(&compare_jobs[i][k],&compare_jobs[j][k]) > 0) {
                    strcpy(temp, print_jobs[i]);
                    strcpy(print_jobs[i], print_jobs[j]);
                    strcpy(print_jobs[j], temp);
                }
            }
        }
    }

    for(int i = 0 ; i < count ; i++){
        printf("%s\n",print_jobs[i]);
        free(print_jobs[i]);
        free(compare_jobs[i]);
    }
    free(print_jobs);
    free(compare_jobs);
}
