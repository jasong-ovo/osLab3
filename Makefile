.o.c:

dups: dupSyscall.o
	gcc -o dups dupSyscall.o

dupf: dupFstream.o
	gcc -o dupf dupFstream.o

dupfscan: dupFscan.o
	gcc -o dupfscan dupFscan.o

dupfgetc: dupFgetc.o
	gcc -o dupfgetc dupFgetc.o

dupfgets: dupFgets.o
	gcc -o dupfgets dupFgets.o

clean:
	rm *.o