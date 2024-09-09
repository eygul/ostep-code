#include <stdio.h>
#include <unistd.h>

int main() {
    int rc = fork(); 

    if (rc < 0) {
        printf("Fork failed...\n");
        
    } else if (rc == 0) {
        printf("Hello");
    } else {
        usleep(100);
        printf("Goodbye");
    }

    return 0;
}

// Eren Gul
// You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent? -- Yes, I was able to. do it without calling wait().
