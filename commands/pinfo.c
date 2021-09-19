#include "pinfo.h"

void command_pinfo(token_mat arg){

    int shell_process = 0;
    if(arg.num_args == 0){
        shell_process = 1;
    }
    char pid[MAX_TOKENS];
    if(!shell_process){
        if(is_bg){
            sprintf(pid,"%d",getppid());
        }
        else{
            sprintf(pid,"%s",arg.args[1]);
        }
    }
    else{
        sprintf(pid,"%d",getpid());
    }

    printf("PID -- %s\n",pid);


}