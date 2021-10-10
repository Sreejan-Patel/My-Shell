#include "pinfo.h"

// gets the info of the process specified
void command_pinfo(token_mat arg){

    if(!arg.num_args){
        char pid[MAX_TOKENS];
        sprintf(pid,"%d",shell_pid);

        char *stat = status(pid);
        if(stat == NULL)
            return;

        char *mem = memory(pid);
        if(mem == NULL)
            return;

        char* executable = exe(pid);
        if(executable == NULL)
            return;

        char *success1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(success1,"PID -- %s\nProcess Status -- %s\nMemory --  %s\nExecutable Path -- %s%s\n",pid,stat,mem,shell,get_relative_path(executable));
        success(success1);
        free(success1);
    }
    else{

        for(int i = 1 ; i <= arg.num_args; i++){
            char pid[MAX_TOKENS];
            int p_pid;
            p_pid = atoi(arg.args[i]);
            sprintf(pid,"%d",p_pid);

            char *stat = status(pid);
            if(stat == NULL)
                return;

            char *mem = memory(pid);
            if(mem == NULL)
                return;

            char *executable = exe(pid);
            if(executable == NULL)
                return;

            char *success1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
            sprintf(success1,"PID -- %s\nProcess Status -- %s\nMemory --  %s\nExecutable Path -- %s\n",pid,stat,mem,executable);
            success(success1);
            free(success1);
        }
    }

}

// gets the status of the process
char* status(char* pid){
    char status[MAX_TOKEN_LENGTH];
    strcpy(status,"/proc/");
    strcat(status,pid);
    strcat(status,"/stat");

    int fd_status = open(status,O_RDONLY);
    if(fd_status < 0){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Opening /proc/pid/stat\n");
        error(error1);
        free(error1);
        return NULL;
    }

    char *temp = malloc(sizeof(char)*1000);
    if(read(fd_status,temp,10000) == 0){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Reading /proc/pid/stat\n");
        error(error1);
        free(error1);
        return NULL;
    }
    close(fd_status);
    strtok(temp, " ");
    strtok(NULL, " ");
    return strtok(NULL, " ");
}

// gets the virtual memory used by the procss
char* memory(char* pid){
    char memory[MAX_TOKEN_LENGTH];
    strcpy(memory,"/proc/");
    strcat(memory,pid);
    strcat(memory,"/statm");

    int fd_mem = open(memory,O_RDONLY);
    if(fd_mem < 0){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Opening /proc/pid/statm\n");
        error(error1);
        free(error1);
        return NULL;
    }
    char *temp1 = malloc(sizeof(char)*1000);
    if(read(fd_mem,temp1,10000) == 0){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Reading /proc/pid/statm\n");
        error(error1);
        free(error1);
        return NULL;
    }
    close(fd_mem);
    return strtok(temp1, " ");

}

// gets the executable path of the process
char* exe(char* pid){
    char exe[MAX_TOKEN_LENGTH];
    strcpy(exe,"/proc/");
    strcat(exe,pid);
    strcat(exe,"/exe");

    char* temp2 = malloc(sizeof(char)*1000);
    long int check = readlink(exe,temp2,1000);
    if(check < 0){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Reading Executable Path\n");
        error(error1);
        free(error1);
        return NULL;
    }
    return temp2;
}
