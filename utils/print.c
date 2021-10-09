#include "print.h"

void error(char* error1){
    printf(ANSI_RED_BOLD "%s" ANSI_DEFAULT , error1);
}

void success(char* success1){
    printf(ANSI_GREEN_BOLD "%s" ANSI_DEFAULT , success1);
}

void prompt(char* prompt1){
    if(is_bg){
        printf(ANSI_CYAN_BOLD "%s" ANSI_PURPLE_BOLD ">" ANSI_DEFAULT , prompt1);
    }
    else{
        printf(ANSI_CYAN_BOLD "%s" ANSI_DEFAULT , prompt1);
    }
}

void prompt_exit(char* exit1){
    printf(ANSI_YELLOW_BOLD "\n\t\t\t\t\t\t\t\t---\t%s\t---\t\t\t\t\t\t\t\t\n" ANSI_DEFAULT,exit1);
}

void alert(char* alert1){
    printf(ANSI_BLUE_BOLD "%s" ANSI_DEFAULT , alert1);
}