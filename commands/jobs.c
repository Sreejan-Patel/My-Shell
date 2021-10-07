#include "jobs.h"

void command_jobs(){
    for(int i = 0; i < MAX_TOKENS && run[i]->pid != 0; i++){
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
            strcpy(final_stat,"Sleeping");
        } else if (strcmp(stat,"Z") == 0) {
            strcpy(final_stat,"Zombie");
        } else if (strcmp(stat,"T") == 0) {
            strcpy(final_stat,"Stopped");
        } else {
            perror("Error status ID! ");
            continue;
        }
        printf("[%d] %s %s [%d]\n",i+1,final_stat,run[i]->name,run[i]->pid);

    }
}
