#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  

int main() {
    int rc = fork();

    if (rc < 0) {
        perror("Fork failed");
        return 1;
    } else if (rc == 0) {
        printf("Child Process (execl):\n");
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        perror("execl failed");

        printf("Child Process (execle):\n");
        char *envp[] = {"PATH=/bin", (char *)0};
        execle("/bin/ls", "ls", "-l", (char *)NULL, envp);
        perror("execle failed");

        printf("Child Process (execlp):\n");
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp failed");

        printf("Child Process (execv):\n");
        char *argvv[] = {"ls", "-l", NULL};
        execv("/bin/ls", argvv);
        perror("execv failed");

        printf("Child Process (execvp):\n");
        execvp("ls", argvv);
        perror("execvp failed");

        printf("Child Process (execvpe):\n");
        execvpe("ls", argvv, envp);
        perror("execvpe failed");

        exit(1); 
    } else {
        wait(NULL); 
    }

    return 0;
}
