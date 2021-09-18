#include "bgprocess.h"

void print_killed_child_process() {

    int pid, status;
    while (1) {
        pid = waitpid(-1, &status,
                      WNOHANG | WUNTRACED); //WNOHANG is for killed children; WUNTRACED is for stopped children
        if (pid <= 0)
            return;

        if (WIFEXITED(status) || WIFSIGNALED(status)) {
            process *prev_process;
            prev_process = malloc(sizeof(process));
            prev_process = running;
            process *current_process;
            current_process = malloc(sizeof(process));
            current_process = running;

            if (current_process != NULL && current_process->pid == pid) {
                running = running->next;
                if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
                    printf("%s with pid %d exited normally with status %d\n", current_process->name, current_process->pid, WEXITSTATUS(status));
                    free(current_process);
                    return;
                }
            }
            while (current_process != NULL && current_process->pid != pid) {
                prev_process = current_process;
                current_process = current_process->next;
            }
            if (current_process != NULL) {
                prev_process->next = current_process->next;
                if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
                    printf("%s with pid %d exited normally with status %d\n", current_process->name, current_process->pid,
                           WEXITSTATUS(status));
                    free(current_process);
                    return;
                }
            }

        }
    }
}


