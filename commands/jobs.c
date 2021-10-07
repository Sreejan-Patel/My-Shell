#include "jobs.h"

void command_jobs(){
    for(int i = 0; i < MAX_TOKENS && run[i]->pid != 0; i++){
        char pid[MAX_TOKENS];
        int p_pid;
        p_pid = atoi(run[i]->pid);
        sprintf(pid,"%d",p_pid);

        char status[MAX_TOKEN_LENGTH];
        strcpy(status,"/proc/");
        strcat(status,pid);
        strcat(status,"/stat");

        int fd_status = open(status,O_RDONLY);
        if(fd_status < 0){
            perror("Error status! ");
            return;
        }

        char *temp = malloc(sizeof(char)*1000);
        if(read(fd_status,temp,10000) == 0){
            perror("Error , couldn't read status! ");
            return;
        }
        close(fd_status);
        strtok(temp, " ");
        strtok(NULL, " ");

        char *stat = strtok(NULL, " ");

    }
}
