# My_Shell

This a project based on assignment 2 of OSN.

It supports a semi-colon separated list of commands and Also, support '&' operator which lets a program run in the background after printing the process id of the newly created process. 

## main.c
Initializes the program.

## globals.c
Contains the global variables used across the files

## utils
### inputmat.c
Initializes a token matrix which stores the input tokens

### files.c
Contains various functions useful.
consists of the following -
>clearscreen : clears the terminal screen
> 
>get_user_name : gets the username operating the system
> 
>get_system_name : gets the systemname
> 
>get_curr_path() : gets the current path
> 
>get_relative_path() : gets the relative path w.r.t shell path

### bgprocessmat.c
Initializes an array of pointers to struct process , which store the name and pid of the bgprocess

## processer
### tokenizer.c

first tokenizes the input w.r.t ";" , second tokenizes the input w.r.t " " and "\t" and then
sends the second tokenized values to execute , to execute the req commands.

### prompt.c

>initialize() : initializes the shell_path , prev_path , shell , in_shell and bgprocessmat.
> 
>prompt_print() : prints the prompt as specified and if there is any bgprocess running a smiley face lets you know.

### bgprocess.c

>print_finished_bgprocess() : prints the info of finished bgprocess

## commands

## pwd.c

Prints the current path

## pinfo.c

Gets the req info of the process specified

## ls.c

Executes the commands ls with various flags.
>dir_arg(..) : checks the dir and calls for the req functions i.e ls_l or ls
> 
> ls(..) : executes ls with/without -a
> 
> ls_l(..) : executes ls with -l flag and with/without -a flag
> 
> get_block_size(..) : gets the total block size

## execvp.c
Executes the non-builtin commands and bg processes

## echo.c
Executes the echo command as specified

## cd.c
Executes the cd command as specified with various flags


# THE END

