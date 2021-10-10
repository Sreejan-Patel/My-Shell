#include "inputmat.h"

// creates a arg matrix which stores the input arg
token_mat make_args_mat(){
    token_mat args_mat;

    args_mat.args = malloc(sizeof(char*)*MAX_TOKENS);
    for(int i = 0 ; i < MAX_TOKENS ; i++){
        args_mat.args[i] = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
    }

    return args_mat;
}