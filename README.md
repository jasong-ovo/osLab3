# test for file operations
# 时间测量
## 
# 文件复制的C语言程序
### 系统调用模式
#include<fcntl.h>
#include <unistd.h>
read(fd, buf, nbytes), write(fd, buf, nbytes), close
#include<stdlib.h>
malloc
#include <string.h>
memset
### 库函数模式(stream)
#include <stdio.h>
fread(buf, size, nitems, fp), fwrite(buf, size, nitems, fp)
## 使用上述两种方式写一个文件复制程序
要求
> * nbytes, size, nitems都取1（即1次1字节）测试两种程序的执行效率
> * nbytes 取 1024 字节， size取1024字节， nitems取1时(即一次读写1024字节)， 测试两种程序的执行效率。
### 使用fscanf和fprintf, fgetc和fputc, fgets和fputs(仅限于行结构文本文件)编写dup程序
include<stdio.h>
feof(fp_source) 用于判断fgetc情况下是否到文件尾.没到结尾时返回0.
但是，这样写也有问题。fgetc()读取文件的最后一个字符以后，C语言的feof()函数依然返回0，表明没有到达文件结尾；只有当fgetc()向后再读取一个字符（即越过最后一个字符），feof()才会返回一个非零值，表示到达文件结尾。
所以，按照上面这样写法，如果一个文件含有n个字符，那么while循环的内部操作会运行n+1次

put 是以删除缓冲区的方式进行的
get 也是先清空再get
