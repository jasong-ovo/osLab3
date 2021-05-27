#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define NBYTES 128

char buf[NBYTES];

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("usage:[main] dFile pipeName\n");
        return -1;
    }
    memset(buf, 0, NBYTES);

    // open read pipe
    mknod(argv[2], S_IFIFO|0666, 0);
    int pfdr = open(argv[2], O_RDONLY);
    if (pfdr == -1) {
        printf("open pipe error!\n");
        return -1;
    }
    int fd_destination = creat(argv[1], 0666);;
    //printf("mark");
    // write to pfdw 
    int size = 0;
    while(size = read(pfdr, buf, NBYTES)){
        printf("size:%d\n", size);
        write(fd_destination, buf, size);
    }
    
    close(fd_destination);
    close(pfdr);
    printf("end of reading\n");
    return 0;
}