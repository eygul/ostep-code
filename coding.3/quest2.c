#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    
    int fd = open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    char parent_msg[] = "Parent process writing before fork.\n";
    write(fd, parent_msg, strlen(parent_msg));

    int rc = fork();

    if (rc < 0) {
        
        perror("Fork failed");
        return 1;
    } else if (rc == 0) {
        
        char child_msg[] = "Child process writing after fork.\n";
        for (int i = 0; i < 5; i++) {
            write(fd, child_msg, strlen(child_msg));
        }
    } else {
        
        char parent_msg_after[] = "Parent process writing after fork.\n";
        for (int i = 0; i < 5; i++) {
            write(fd, parent_msg_after, strlen(parent_msg_after));
        }
        wait(NULL);
    }

    close(fd);
    return 0;
}
