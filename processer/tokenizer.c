#include "tokenizer.h"
/*
    -first tokenizes the input w.r.t ;
    -second tokenizes the input w.r.t " " and "\t"
    -sends the second tokenized values to execute , to execute the req commands
*/
void tokenize_input(char *input){
    token_mat args_mat;
    args_mat = make_args_mat();

    char *token;
    token = strtok(input,";");
    int i = 0;

    while (token != NULL) // store the tokenized string in a token matrix
    {
        strcpy(args_mat.args[i], token);
        token = strtok(NULL, ";");
        i++;
    }

    args_mat.num_args = i - 1; // number of different commands
    args_mat.args[i] = token;

    tokenize(args_mat);

}

void tokenize(token_mat args_mat){
    token_mat arg;

    for(int i  = 0 ; i <= args_mat.num_args ; i++){
        arg = make_args_mat();
        char *token;
        token = strtok(args_mat.args[i]," \t");

        int j = 0;
        long int repeat = 0;
        int is_repeat = 0;
        while(token != NULL){
            if(strcmp(token,"repeat") == 0){
                is_repeat++;
            }
            if(is_repeat == 1){
                token = strtok(NULL, " \t");
                is_repeat++;
                continue;
            }
            if(is_repeat == 2){
                repeat = strtol(token,NULL,10);
                if(repeat == 0){
                    perror("Error");
                    return;
                }
                token = strtok(NULL, " \t");
                is_repeat++;
                continue;
            }
            strcpy(arg.args[j],token);
            token = strtok(NULL, " \t");
            j++;
        }

        arg.num_args = j - 1;
        arg.args[j] = token;


        int mode = 0;
        for(int k = 0 ; k <= arg.num_args ; k++){
            if(strcmp(arg.args[k],"<") == 0)
                mode = 1;
            else if(strcmp(arg.args[k],">") == 0)
                mode = 2;
            else if(strcmp(arg.args[k],">>") == 0)
                mode = 3;
        }
        if(mode){
            redirections(arg,repeat);
            return;
        }

        execute(arg,repeat);

    }
}

void execute(token_mat arg,long int repeat){
    long int n = repeat;
    if(!n){
        if(strcmp(arg.args[0],"echo") == 0){
            command_echo(arg);
        }
        else if(strcmp(arg.args[0],"pwd") == 0){
            command_pwd(arg);
        }
        else if(strcmp(arg.args[0],"cd") == 0){
            command_cd(arg);
        }
        else if(strcmp(arg.args[0],"ls") == 0){
            command_ls(arg);
        }
        else if(strcmp(arg.args[0],"pinfo") == 0){
            command_pinfo(arg);
        }
        else{
            command_execvp(arg);
        }
    }
    else{
        while(n--){
            if(strcmp(arg.args[0],"echo") == 0){
                command_echo(arg);
            }
            else if(strcmp(arg.args[0],"pwd") == 0){
                command_pwd(arg);
            }
            else if(strcmp(arg.args[0],"cd") == 0){
                command_cd(arg);
            }
            else if(strcmp(arg.args[0],"ls") == 0){
                command_ls(arg);
            }
            else if(strcmp(arg.args[0],"pinfo") == 0){
                command_pinfo(arg);
            }
            else{
                command_execvp(arg);
            }
        }
    }
}


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
    int fd_in = -1;
    int fd_out = -1;
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
