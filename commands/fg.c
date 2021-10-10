#include "fg.h"

// brings a stopped or running bgprocess to fg
void command_fg(token_mat arg){
    if(arg.num_args != 1){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: fg - Wrong Arguments\n");
        error(error1);
        free(error1);
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
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: sig - Invalid Job NUmber\n");
        error(error1);
        free(error1);
        return;
    }

    int job_pid = run[job_number-1]->pid;

    strcpy(fg_run[0]->name,run[job_number-1]->name);
    fg_run[0]->pid = job_pid;

    delete_process(job_number-1);

    // protect shell against signals for illegal use of stdin and stdout
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);

    // make the job's process group the foreground process group
    tcsetpgrp(STDIN_FILENO, job_pid);

    // ask job to continue
    if(kill(job_pid, SIGCONT) < 0){
        perror("Error SIGCONT! ");
        return;
    }

    char *alert1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
    sprintf(alert1,"Alert: [%d] %s [%d] Background process resumed in Foreground\n", job_number, fg_run[0]->name, fg_run[0]->pid);
    alert(alert1);
    free(alert1);

    // wait for job to complete
    int stat;
    waitpid(job_pid, &stat, WUNTRACED);

    // job is completed, now make shell the foreground process group again
    tcsetpgrp(STDIN_FILENO, getpgrp());

    // safe to end protection from signals
    signal(SIGTTIN, SIG_DFL);
    signal(SIGTTOU, SIG_DFL);

    if(WIFSTOPPED(stat)){       // ctrl-z
        char *alert2 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(alert2,"\tAlert: %s process with ID %d has been stopped by CTRL-Z\n",fg_run[0]->name,job_pid);
        alert(alert2);
        free(alert2);
        add_fgprocess();
    }
    else if(WIFSIGNALED(stat)){     // any signal
        char *alert2 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(alert2,"\tAlert: %s process with ID %d has received a signal %d\n",fg_run[0]->name,job_pid, WTERMSIG(stat));
        alert(alert2);
        free(alert2);
    }

}