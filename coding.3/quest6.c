#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) 
    {
        printf("This is the child process\n");
    }
    else if (rc > 0) 
    {
        int status;
        int wc = waitpid(rc, &status, 0);
        printf("This is the parent process\n");
        printf("Return code from waitpid() is %d\n", wc);
    }
    else 
    {
        fprintf(stderr, "Fork failed...\n");
    }

    return 0;
}
