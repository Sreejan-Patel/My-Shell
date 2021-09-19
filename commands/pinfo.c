#include "pinfo.h"

// gets the info of the process specified

void command_pinfo(token_mat arg){

    if(!arg.num_args){
        char pid[MAX_TOKENS];
        int shell_pid;
        shell_pid = getpid();
        sprintf(pid,"%d",shell_pid);

        printf("PID -- %s\n",pid);
        printf("Process Status -- R\n");
        char path[PROC_PIDPATHINFO_MAXSIZE];
        proc_pidpath(shell_pid, path, sizeof(path));
        printf("Executable Path -- ~%s\n", get_relative_path(path));


    }
    else{

        for(int i = 1 ; i <= arg.num_args; i++){
            char pid[MAX_TOKENS];
            int p_pid;
            p_pid = atoi(arg.args[i]);
            sprintf(pid,"%d",p_pid);

            printf("PID -- %s\n",pid);

            char path[PROC_PIDPATHINFO_MAXSIZE];
            if(!proc_pidpath(p_pid, path, sizeof(path))){
                perror("Error!");
                break;
            }
            if(strncpy(shell_path,path,shell_path_length) == 0)
                printf("Executable Path -- %s\n", get_relative_path(path));
            else
                printf("Executable Path -- %s\n", path);
        }
    }

}