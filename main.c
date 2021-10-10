#include "globals.h"
#include "processer/prompt.h"
#include "processer/tokenizer.h"

int main() {
    clear_screen(); // clears the screen
    initialize();   // initialize the necessary functions
    int i;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while(!0){
        // since the terminal regains control only after a fg process if complete
        fg_run[0]->pid = -1;
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
            // '\377' character identifies CTRL-D
            if(temp == '\377'){
                char *exit1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
                sprintf(exit1,"Exiting -- My_Shell");
                prompt_exit(exit1);
                free(exit1);
                exit(0);
            }
            else if (temp != '\n')
                input[i++] = temp;
            else {
                input[i] = '\0';
                break;
            }
        }
        // tokenize input
        tokenize_input(input);

    }
#pragma clang diagnostic pop


    return 0;
}
