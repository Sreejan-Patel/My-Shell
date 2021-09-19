#include "pwd.h"

// prints the current path

void command_pwd(token_mat arg){
    printf("%s\n",get_curr_path());
}

