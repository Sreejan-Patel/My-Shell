#include "echo.h"

void command_echo(token_mat arg){
    int i = arg.num_args;
    for(int j = 1 ; j <= i ; j++){
        printf("%s ",arg.args[j]);
    }
    printf("\n");

}