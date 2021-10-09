#include "echo.h"

// executes the echo command as specified

void command_echo(token_mat arg){
    int i = arg.num_args;
    for(int j = 1 ; j <= i ; j++){
        printf(ANSI_GREEN_BOLD"%s "ANSI_DEFAULT,arg.args[j]);
    }
    printf("\n");

}