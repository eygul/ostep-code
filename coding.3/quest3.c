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
