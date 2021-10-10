--- Welcome To My_Shell ---
---
_The Bash Shell in a Nut Shell -- My_Shell._

My_Shell supports a semi-colon(';') separated list of commands ,accounts for random spaces and tabs and Also, support '&' operator which lets a program run in the background after printing the process id of the newly created process.

---
## Compiling And Running

A Makefile has been included for compiling the code.
```sh
    > make
    > ./My_Shell
```

`CTRL-D` is the only way to Exit My_Shell

---

## Features

#### Prompt
- `<user_name@system_name:~>`
- displays the user_name and system_name of the system
- `~` is the home directory , which is the path where the `My_Shell` executable is present
- `<user_name@system_name:~>>` The extra `>` indicates the presence of bgprocess

#### Execvp
- Non-Builtin functions are executed with the help of `execvp()`
- The `&` operator implies the process to be run on the background else on the foreground

#### Foreground processes
- My_Shell waits for the current process to execute.

#### Background processes
- Use of '&' at the end of any command invokes a background process
- The bgprocess gets added into a list of jobs which contain its name and pid 
- The bgprocess will run in the background and when exited(_normally/forcefully_), a message will be displayed
- if there are any bgprocess Running/Stopped in the background the prompt displays extra `>` to indicate the same 

#### Input/Output redirection
- `> <output_file>` - redirects output and overwrites to the specified output_file
- `>> <output_file>` - redirects output and appends to the specified output_file
- `< <input_file>` - redirects input from the specified input_file

#### Redirection using Pipes
- `|` - operator specifies the implementation of piping 
- The output of one side of the pipe is passed as input to the other side of the pipe
- Pipes and i/o redirection are done together


#### Signals
- **CTRL+C** - interrupts any currently running foreground job, by sending it the SIGINT signal. Has no effect on the shell if there is no foreground process running.
- **CTRL+Z** - pushes any currently running foreground job into the background, and change its state from running to stopped.Has no effect on the shell if there is no foreground process running.
- **CTRL+D** - Exits My_Shell safely

---

## Built-In Commands

#### ls command
- ls takes arguments as flags (-<flagname>) and directories (<directory name>)
- It lists the files of the directory mentioned. If no directory is mentioned, it lists the files in the current directory
- `ls -l` - long list
- `ls -a` - display hidden files
- `ls -al/-la/-a -l/-l -a` - long list including hidden files

#### cd command
- `cd <absolute path>` - goes to absolute path
- `cd` - goes to ~
- `cd ~/<pathname>` - goes to ~/<pathname>
- `cd ..` - goes to previous directory
- `cd .` - stays in the same directory
- `cd -` - goes to the prev_path

#### echo command
- `echo` - prints empty line
- `echo text` - prints text
- `echo "text"` / `echo 'text'` - prints "text"/'text'
- `echo` handles tabs and spaces and prints with a single space in between 

#### pwd command
- `pwd` - prints absolute path of current directory

#### pinfo command
- `pinfo` - prints process info of the shell
- `pinfo <pid>` - prints process info of given pid
- The Info consists of: PID , Status , Virtual Memory and Executable path of the process


#### jobs command
- `jobs` - prints a list of all background processes
- `jobs -r` - prints a list of all running background processes
- `jobs -s` - prints a list of all stopped background processes

#### sig command
- `sig <jobnumber> <signal>` - takes the job id of a running job and sends a signal to that process

#### fg command
- `fg <jobnumber>` - brings a running or a stopped background job with given job number to foreground

#### bg command
- `bg <jobnumber>` - changes a stopped background job to a running background job

---

- `globals.h` - consists of all the header files required , definitions and external variables used throughout the project

- `main.c` - contains the main while loop , reads input and initializes the requirements of My_Shell

- `print.c` - prints the strings in various colours
- `run` - an array of pointers to struct , stores the info of the bgprocesses
- `fg_run` - a pointer to struct , stores the current fgprocess (Non-Inbuilt)

---

_To Understand the detailed implementation of each function/feature follow along the code and hope the detailed comments help_

---

# _--- Exiting -- My_Shell ---_

