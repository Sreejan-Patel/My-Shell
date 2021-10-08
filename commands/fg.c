#include "fg.h"

void command_fg(token_mat arg){
    if(arg.num_args != 1){
        printf("Error Invalid Arguments!\n");
        return;
    }

    int count = -1;
    for(int i = 0 ; i < MAX_TOKENS ; i++){
        if(run[i]->name[0] == '\0')
            break;
        else
            count++;
    }

    int job_number = atoi(arg.args[1]);

    if(job_number < 1 || job_number > count+1){
        printf("Error Invalid job_number!\n");
        return;
    }

    int job_pid = run[job_number-1]->pid;

    printf("[%d] %s %d background process resumed!\n", job_number, run[job_number-1]->name, job_pid);

    strcpy(fg_run[0]->name,run[job_number-1]->name);
    fg_run[0]->pid = job_pid;

    delete_process(job_number-1);

    // protect shell against signals for illegal use of stdin and stdout
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);

    // It is already a separate group
    // make the job's process group the foreground process group
    tcsetpgrp(STDIN_FILENO, job_pid);

    // ask job to continue
    kill(job_pid, SIGCONT);

    // wait for job to complete
    int stat;
    waitpid(job_pid, &stat, WUNTRACED);

    // job is completed, now make shell the foreground process group again
    tcsetpgrp(STDIN_FILENO, getpgrp());

    // safe to end protection from signals
    signal(SIGTTIN, SIG_DFL);
    signal(SIGTTOU, SIG_DFL);

    if(WIFSTOPPED(stat)){
        printf("%s process with ID %d has been stopped!\n",fg_run[0]->name,job_pid);
    }
    else if(WIFSIGNALED(stat)){
        printf("%s process with ID %d has received a signal %d!\n",fg_run[0]->name,job_pid, WTERMSIG(stat));
    }

}