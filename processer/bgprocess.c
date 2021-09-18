#include "bgprocess.h"

/**
 * Display the name and pid of all children killed or stopped within the next execution of the command
 * Runs on pressing enter
 */


void print_proc_details(process *proc, int status)
{
    char buffer[MAX_TOKEN_LENGTH];
    if (WIFEXITED(status))
        sprintf(buffer, "%s with pid %d exited normally with status %d", proc->pname, proc->pid, WEXITSTATUS(status));
    else
        sprintf(buffer, "%s with pid %d exited abnormally with error status %d", proc->pname, proc->pid, WEXITSTATUS(status));
    print_n(buffer);
}

void display_killed_children()
{
    int pid, status;
    while (1)
    {
        pid = waitpid(-1, &status, WNOHANG | WUNTRACED); //WNOHANG is for killed children; WUNTRACED is for stopped children
        if (pid <= 0)
            break;
        if (WIFEXITED(status) || WIFSIGNALED(status))
        {
            process *prev_proc = running, *current_proc = running;
            if (current_proc != NULL && current_proc->pid == pid)
            {
                running = running->next;
                print_proc_details(current_proc, status);
                free(current_proc);
                return;
            }
            while (current_proc != NULL && current_proc->pid != pid)
            {
                prev_proc = current_proc;
                current_proc = current_proc->next;
            }
            if (current_proc != NULL)
            {
                prev_proc->next = current_proc->next;
                print_proc_details(current_proc, status);
                free(current_proc);
                return;
            }
        }
    }
}

void print_n(char *s)
{
    print(s);
    print("\n");
}

void print(char *s)
{
    write(1, s, strlen(s));
}