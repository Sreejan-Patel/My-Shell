cmake_minimum_required(VERSION 3.20)
project(My_Shell C)

set(CMAKE_C_STANDARD 99)

add_executable(My_Shell main.c utils/util.c utils/util.h globals.c globals.h processer/prompt.c processer/prompt.h processer/tokenizer.c processer/tokenizer.h utils/inputmat.c utils/inputmat.h commands/echo.c commands/echo.h commands/pwd.c commands/pwd.h commands/cd.c commands/cd.h commands/ls.c commands/ls.h processer/bgprocess.c processer/bgprocess.h commands/execvp.c commands/execvp.h commands/pinfo.c commands/pinfo.h utils/processmat.c utils/processmat.h processer/redirections.c processer/redirections.h processer/pipeline.c processer/pipeline.h commands/jobs.c commands/jobs.h commands/sig.c commands/sig.h commands/fg.c commands/fg.h processer/signals.c processer/signals.h commands/bg.c commands/bg.h utils/process.c utils/process.h utils/print.c utils/print.h)
