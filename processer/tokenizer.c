#include "tokenizer.h"

void tokenize_input(char *input){
    token_mat args_mat;
    args_mat = make_args_mat();

    char *token;
    token = strtok(input,";");  // tokenize ;
    int i = 0;

    while (token != NULL) // store the tokenized string in a token matrix
    {
        strcpy(args_mat.args[i], token);
        token = strtok(NULL, ";");
        i++;
    }

    args_mat.num_args = i - 1; // number of arguments of the command
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

        // removes the repeat token and stores the repeat_value
        // tokenize input
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

        arg.num_args = j - 1;   // number of arguments of the command
        arg.args[j] = token;

        // checks for redirections and pipeline
        int mode = 0;
        for(int k = 0 ; k <= arg.num_args ; k++){
            if(strcmp(arg.args[k],"<") == 0){
                mode = 1;
            }
            else if(strcmp(arg.args[k],">") == 0){
                mode = 2;
            }
            else if(strcmp(arg.args[k],">>") == 0){
                mode = 3;
            }
            else if(strcmp(arg.args[k],"|") == 0){
                mode = 4;
                break;
            }
        }
        if(mode == 4){
            pipeline(arg,repeat);
            return;
        }
        else if(mode){
            redirections(arg,repeat);
            return;
        }
        else
            execute(arg,repeat);

    }
}

// executes the given command
// checks for inbuilt-commands
// else execvp
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
        else if(strcmp(arg.args[0],"jobs") == 0){
            command_jobs(arg);
        }
        else if(strcmp(arg.args[0],"sig") == 0){
            command_sig(arg);
        }
        else if(strcmp(arg.args[0],"fg") == 0){
            command_fg(arg);
        }
        else if(strcmp(arg.args[0],"bg") == 0){
            command_bg(arg);
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
            else if(strcmp(arg.args[0],"jobs") == 0){
                command_jobs(arg);
            }
            else if(strcmp(arg.args[0],"sig") == 0){
                command_sig(arg);
            }
            else if(strcmp(arg.args[0],"fg") == 0){
                command_fg(arg);
            }
            else if(strcmp(arg.args[0],"bg") == 0){
                command_bg(arg);
            }
            else{
                command_execvp(arg);
            }
        }
    }
}



