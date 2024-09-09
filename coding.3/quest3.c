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
// Write another program using fork(). The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling wait() in the parent?
// Answer: Yes, I was able to. do it without calling wait().
