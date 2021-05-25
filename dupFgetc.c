#include <stdio.h>

char buf[1];

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("usage:[main] sFile dFile\n");
        return -1;
    }

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

    //read and write
    char c;
    while (1)
    {   
        c = fgetc(fp_source);
        if(feof(fp_source)) break;
        fputc(c, fp_destination);
    }
    
    return 0;
}