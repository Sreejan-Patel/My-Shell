#include "pinfo.h"

// gets the info of the process specified

void command_pinfo(token_mat arg){

    if(!arg.num_args){
        char pid[MAX_TOKENS];
        int shell_pid;
        shell_pid = getpid();
        sprintf(pid,"%d",shell_pid);

        printf("PID -- %s\n",pid);

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

        printf("Process Status -- %s\n", strtok(NULL, " "));

        char memory[MAX_TOKEN_LENGTH];
        strcpy(memory,"/proc/");
        strcat(memory,pid);
        strcat(memory,"/statm");

        int fd_mem = open(memory,O_RDONLY);
        char *temp1 = malloc(sizeof(char)*1000);
        if(read(fd_status,temp1,10000) == 0){
            perror("Error , couldn't read memory! ");
            return;
        }
        close(fd_mem);
        char *mem = strtok(temp1, " ");
        printf("Memory --  %s\n",mem);

        char exe[MAX_TOKEN_LENGTH];
        strcpy(exe,"/proc/");
        strcat(exe,pid);
        strcat(exe,"/exe");

        char* temp2 = malloc(sizeof(char)*1000);
        int check = readlink(exe,temp2,1000);
        if(check < 0){
            perror("Error Executable Path! ");
            return;
        }

        printf("Executable Path -- %s%s\n",shell, get_relative_path(temp2));

        free(temp);
        free(temp1);
        free(temp2);



    }
    else{

        for(int i = 1 ; i <= arg.num_args; i++){
            char pid[MAX_TOKENS];
            int p_pid;
            p_pid = atoi(arg.args[i]);
            sprintf(pid,"%d",p_pid);

            printf("PID -- %s\n",pid);

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

            printf("Process Status -- %s\n", strtok(NULL, " "));

            char memory[MAX_TOKEN_LENGTH];
            strcpy(memory,"/proc/");
            strcat(memory,pid);
            strcat(memory,"/statm");

            int fd_mem = open(memory,O_RDONLY);
            char *temp1 = malloc(sizeof(char)*1000);
            if(read(fd_status,temp1,10000) == 0){
                perror("Error , couldn't read memory! ");
                return;
            }
            close(fd_mem);
            char *mem = strtok(temp1, " ");
            printf("Memory --  %s\n",mem);

            char exe[MAX_TOKEN_LENGTH];
            strcpy(exe,"/proc/");
            strcat(exe,pid);
            strcat(exe,"/exe");

            char* temp2 = malloc(sizeof(char)*1000);
            int check = readlink(exe,temp2,1000);
            if(check < 0){
                perror("Error Executable Path! ");
                return;
            }
            printf("Executable path -- %s\n",temp2);


            free(temp);
            free(temp1);
            free(temp2);



        }
    }

}
