#include "tokenizer.h"

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

        while(token != NULL){
            strcpy(arg.args[j],token);
            token = strtok(NULL, " \t");
            j++;
        }

        arg.num_args = j - 1;
        arg.args[j] = token;

        execute(arg);

    }
}

void execute(token_mat arg){

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
    else{
        command_execvp(arg);
    }
}