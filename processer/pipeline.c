#include "pipeline.h"

void pipeline(token_mat arg,long int repeat){
    int pipe_num = 0;

    for(int i = 0 ; i <= arg.num_args ; i++){
        if(strcmp(arg.args[i],"|") == 0)
            pipe_num++;
    }

    token_mat command[pipe_num+1];
    for(int i = 0 ; i <= pipe_num ; i++){
        command[i] = make_args_mat();
    }

    int pipe_mode = 0;
    int j = 0;
    for(int i = 0 ; i <= arg.num_args ; i++){
        if(strcmp(arg.args[i],"|") == 0){
            command[pipe_mode].num_args = j - 1;
            pipe_mode++;
            j = 0;
            if(arg.num_args < i + 1){
                printf("Error! Wrong implementation of pipeline\n");
                return;
            }
        }
        else{
            command[pipe_mode].args[j] = arg.args[i];
            j++;
        }
    }
    command[pipe_mode].num_args = j - 1;


    int stdin = dup(STDIN_FILENO);
    int stdout = dup(STDOUT_FILENO);

    int fd[2];
    int fd_in = 0;

    for(int i = 0 ; i <= pipe_num ; i++){
        if(pipe(fd) < 0){
            perror("Error Piping! ");
            return;
        }

        int pid = fork();
        if(pid < 0){
            perror("Error forking in pipeline! ");
            return;
        }
        else if (pid == 0) {
            dup2(fd_in, STDIN_FILENO);
            if (i != (pipe_num))
                dup2(fd[1], STDOUT_FILENO);
            close(fd[0]);
            redirections(command[i],repeat);
            exit(0);
        }
        else {
            wait(NULL);
            close(fd[1]);
            fd_in = fd[0];
        }
    }

    dup2(stdin, STDIN_FILENO);
    dup2(stdout, STDOUT_FILENO);


}