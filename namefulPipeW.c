#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define NBYTES 128

char buf[NBYTES];

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("usage:[main] sFile pipeName\n");
        return -1;
    }
    memset(buf, 0, NBYTES);

    // open writed pipe
    mknod(argv[2], S_IFIFO|0666, 0);
    int pfdw = open(argv[2], O_WRONLY);
    int fd_source = open(argv[1], O_RDONLY|O_NDELAY);

    // write to pfdw 
    int size = 0;
    while(size = read(fd_source, buf, NBYTES)){
        printf("size:%d\n", size);
        write(pfdw, buf, size);
    }

    close(fd_source);
    close(pfdw);
    printf("end of writing\n");
    return 0;
}