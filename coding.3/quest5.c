#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) 
    {
        int wc = wait(NULL);
        printf("This is the child process\n");
        printf("Return code from wait() is %d\n", wc);
    }
    else if (rc > 0) 
    {
        printf("This is the parent process\n");
    }
    else if (rc < 0)
    {
        fprintf(stderr, "Fork failed...");
    }
}

// Eren Gul
// Now write a program that uses wait() to wait for the child process to finish in the parent. What does wait() return? What happens if you use wait() in the child?
// Answer: wait() returns -1. When the wait() method is used in the child process, the parent process runs first.
