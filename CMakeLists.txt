cmake_minimum_required(VERSION 3.20)
project(My_Shell C)

set(CMAKE_C_STANDARD 99)

add_executable(My_Shell main.c utils/files.c utils/files.h globals.c globals.h processer/prompt.c processer/prompt.h processer/tokenizer.c processer/tokenizer.h utils/inputmat.c utils/inputmat.h commands/echo.c commands/echo.h commands/pwd.c commands/pwd.h commands/cd.c commands/cd.h commands/ls.c commands/ls.h processer/bgprocess.c processer/bgprocess.h commands/execvp.c commands/execvp.h commands/pinfo.c commands/pinfo.h utils/bgprocessmat.c utils/bgprocessmat.h)
