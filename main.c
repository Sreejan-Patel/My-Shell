#include <stdio.h>
#include "utils/files.h"
#include "globals.h"
#include "processer/prompt.h"
#include "processer/tokenizer.h"
#include "processer/bgprocess.h"

int main() {
    clear_screen();
    initialize();
    int i;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while(!0){
        fg_run[0]->pid = -1;
        print_finished_bgprocess();

        // check if any bg processes are still running
        if(run[0]->name[0] == '\0')
            is_bg = 0;

        else
            is_bg = 1;
        prompt_print();     //prints prompt


        // take input
        char temp;
        char *input;
        input = (char*) malloc(sizeof(char)*MAX_TOKEN_LENGTH);
        i = 0;
        while (1) {
            temp = (char)getchar();
            if(temp == '\377'){
                printf("\nExiting My_Shell\n");
                exit(0);
            }
            else if (temp != '\n')
                input[i++] = temp;
            else {
                input[i] = '\0';
                break;
            }
        }

        tokenize_input(input);

    }
#pragma clang diagnostic pop


    return 0;
}
