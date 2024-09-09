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