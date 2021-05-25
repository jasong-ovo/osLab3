#include <stdio.h>
#include <string.h>

#define NITEMS 1
#define SIZE 1024

char buf[1024];

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("usage:[main] sFile dFile\n");
        return -1;
    }
    memset(buf, 0, 1024);

    //open file
    FILE *fp_source = fopen(argv[1], "r");
    if (fp_source == NULL) {
        printf("error!! open source file failed!\n");
        return -1;
    }
    FILE *fp_destination = fopen(argv[2], "w") ;
    if (fp_destination == NULL) {
        printf("error!! open destination file failed!\n");
        return -1;
    }

    //read from source and write to destination
    int n=0;
    while (n = fread(buf, SIZE, NITEMS, fp_source)){
        fwrite(buf, SIZE, n, fp_destination);
    }

    fclose(fp_source);
    fclose(fp_destination);
    return 0;
}