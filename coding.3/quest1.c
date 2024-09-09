#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 100;
    printf("Before forking, x= %d\n", x);  
    int rc = fork(); 

    if (rc < 0) {
        
        printf("Fork failed...\n");
        
    } else if (rc == 0) {
        
        printf("Child process: x= %d\n", x);
        x = 101;  
        printf("New value of x= %d\n", x);
    } else {
        printf("Parent process: x= %d\n", x);
        x = 102;  
        printf("New value of x= %d\n", x);
    }

    return 0;
}


// Eren Gul
// What value is the variable in the child process? -- The value in the child process is 101.
// What happens to the variable when both the child and parent change the value of x? -- The value of the variable gets overwritten by the last process that changes the value of the variable.

