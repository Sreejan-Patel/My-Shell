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
        print_killed_child_process();
        prompt_print();

        char temp;
        char *input;
        input = (char*) malloc(sizeof(char)*MAX_TOKEN_LENGTH);
        i = 0;
        while (1) {
            temp = (char)getchar();
            if (temp != '\n')
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
