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
        if(strcmp(arg.args[arg.num_args],"&") == 0) {
            is_bg = 1;
        }
        else{
            is_bg = 0;
        }
        int child = fork();
        if(child == -1){
            perror("Error, Could not fork child! ");
        }
        else if(child == 0) {
            // child process
            if (is_bg) {
                setpgid(0, 0);
            }

            int i;
            char *temp[MAX_TOKENS];
            for (i = 0; i < MAX_TOKENS; i++) {
                if (arg.args[i] != NULL) {
                    temp[i] = arg.args[i];
                } else
                    break;
            }
            temp[i] = NULL;

            if (is_bg) {
                temp[i-1] = NULL;
                if (execvp(temp[0], temp) < 0) //If the command does not exist
                    perror("Error execvp! ");
            }
            else
                if (execvp(temp[0], temp) < 0) //If the command does not exist
                    perror("Error execvp! ");

        }
        else {
            int i;
            if (!is_bg)
                waitpid(child, &i, WUNTRACED); //if it is not a background process, wait, till it gets over
            else {
                process *x;
                x = malloc(sizeof(process));
                strcpy(x->pname, arg.args[0]);
                x->pid = child;
                x->next = running;
                running = x;
            }
        }


    }
}