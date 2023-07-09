CC1=arm-linux-gnueabihf-gcc
CC=gcc
OUT=hello_x86
OUT1=hello_arm
$(OUT): hello.o
	$(CC) hello.o -o $(OUT)
hello.o: hello.S
	$(CC) -c hello.S -o hello.o
hello.S: hello.i
	$(CC) -S hello.i -o hello.S
hello.i: hello.c
	$(CC) -E hello.c -o hello.i

clean:
	rm -rf *.o *.i *.S hello_x86 hello_arm
