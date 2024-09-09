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