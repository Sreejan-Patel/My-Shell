#include "jobs.h"

void command_jobs(){
    for(int i = 0; i < MAX_TOKENS && run[i]->pid != 0; i++){
        char pid[MAX_TOKENS];
        int p_pid;
        p_pid = atoi(run[i]->pid);
        sprintf(pid,"%d",p_pid);

        char final_stat[MAX_TOKENS];
        char *stat = status(pid);
        if (stat == NULL) {
            continue;
        }
        else if (stat[0] == 'R') {
            strcpy(final_stat,"Running");
        } else if (stat[0] == 'S' || stat[0] == 'D') {
            strcpy(final_stat,"Sleeping");
        } else if (stat[0] == 'Z' || stat[0] == 'z') {
            strcpy(final_stat,"Zombie");
        } else if (stat[0] == 'T' || stat[0] == 't') {
            strcpy(final_stat,"Stopped");
        } else {
            perror("Error status ID! ");
            continue;
        }
        printf("[%d] %s %s [%d]\n",i+1,final_stat,run[i]->name,run[i]->pid);

    }
}
