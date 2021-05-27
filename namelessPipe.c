#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define NBYTES 128

char buf[NBYTES];

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("usage:[main] sFile dFile\n");
        return -1;
    }
    memset(buf, 0, NBYTES);

    //fpd[0] read; fpd[1] write
    int fpd[2];
    if (pipe(fpd) == -1) {
        printf("init pipe failed!\n");
        return -1;
    };
    pid_t pid;

    //father process
    pid = fork();
    if (pid == -1) {
        printf("init child process failed!\n");
        return -1;
    }
    //father process
    if (pid){
        close(fpd[0]);
        //open read file
        int fd_source = open(argv[1], O_RDONLY);
        if (fd_source == -1) {
        printf("error:source:%s doesn't exsit\n", argv[1]);
        return -1;
        }
        //read to buf and write to pipe
        // while file !EOF read file and write to another
        int size = 0;
        while (size = read(fd_source, buf, NBYTES)) {
            // printf("size:%d\n", size);
            write(fpd[1], buf, size);
        }
        close(fd_source);
        close(fpd[1]);
    }
    //child process
    else {
        close(fpd[1]);
        //open writed file
        int fd_destination = creat(argv[2], 0666);
        if (fd_destination == -1) {
            printf("error:destenation:%s couldn't be created\n", argv[2]);
            return -1;
        }
            // read from pipe and write to des
        int size = 0;
        while (size = read(fpd[0], buf, NBYTES)) {
            write(fd_destination, buf, size);
        }
        close(fd_destination);
        close(fpd[0]);
    }

    return 0;
}