#include "pwd.h"

// prints the current path

void command_pwd(token_mat arg){
    char *success1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
    sprintf(success1,"%s\n",get_curr_path());
    success(success1);
    free(success1);
}

