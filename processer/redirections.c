#include "redirections.h"

void redirections(token_mat arg,long int repeat){
    char *input_file = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
    char *output_file = malloc(sizeof(char)*MAX_TOKEN_LENGTH);

    token_mat command;
    command = make_args_mat();

    int command_num = 0;
    int mode = 0;
    for (int i = 0; i <= arg.num_args ; i++) {
        if (strcmp(arg.args[i],"<") == 0)
            mode = 1;
        else if (strcmp(arg.args[i],">") == 0)
            mode = 2;
        else if(strcmp(arg.args[i],">>") == 0)
            mode = 3;
        else if (mode == 0) {
            command.args[command_num] = arg.args[i];
            command_num++;
        }
        else if (mode == 1) {
            strcpy(input_file,arg.args[i]);
        }
        else if (mode == 2 || mode == 3) {
            strcpy(output_file,arg.args[i]);
        }
    }
    command.num_args = command_num - 1;
    command.args[command_num] = NULL;

    int stdin = dup(STDIN_FILENO);
    int stdout = dup(STDOUT_FILENO);
    int fd_in;
    int fd_out;
    if(strlen(input_file) != 0){
        fd_in = open(input_file,O_RDONLY);
        if(fd_in < 0){
            perror("Error , Input file!");
            return;
        }
        dup2(fd_in,STDIN_FILENO);
    }

    if(strlen(output_file) != 0){
        int write_mode;
        if(mode == 3)
            write_mode = O_APPEND;
        else
            write_mode = O_TRUNC;

        fd_out = open(output_file,O_CREAT | O_WRONLY | write_mode , 0644);
        if(fd_out < 0){
            perror("Error , Output file!");
            return;
        }
        dup2(fd_out,STDOUT_FILENO);
    }

    execute(command,repeat);

    if(fd_in >= 0)
        close(fd_in);
    if (fd_out >= 0)
        close(fd_out);
    dup2(stdin, STDIN_FILENO);
    dup2(stdout, STDOUT_FILENO);

    free(input_file);
    free(output_file);


}