#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();
    if (rc == 0){
        close(STDOUT_FILENO);
        printf("Test\n");
    }
    else if (rc > 0){
        wait(NULL);
        printf("This is the parent process\n");
    }
    else if (rc < 0){
        printf("Fork failed.\n");
    }
}

// Eren Gul

// Write a program that creates a child process, and then in the child closes standard output (STDOUT FILENO). What happens if the child calls printf() to print some output after closing the descriptor?
// Answer: The child process ends up not printing out the statement. In my program's case, `printf("Test\n")` does not get printed.
