#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NBYTES 1024

char buf[1024];

int main(int argc,char *argv[]){
    memset(buf, 0, 1024);
    if (argc != 3) {
        printf("usage:[main] sFile dFile\n");
        return -1;
    }
    printf("duplicate from source:%s to destination:%s\n", argv[1], argv[2]);

    //open source and destination
    int fd_source = open(argv[1], O_RDONLY);
    if (fd_source == -1) {
        printf("error:source:%s doesn't exsit\n", argv[1]);
        return -1;
    }
    int fd_destination = creat(argv[2], 0666);
    if (fd_destination == -1) {
        printf("error:destenation:%s couldn't be created\n", argv[2]);
        return -1;
    }

    // while file !EOF read file and write to another
    int size = 0;
    while (size = read(fd_source, buf, NBYTES)) {
        write(fd_destination, buf, size);
    }

    close(fd_source);
    close(fd_destination);
    return 0;
}

