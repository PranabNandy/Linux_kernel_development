# CC=arm-linux-gnueabihf-gcc
# CC1=gcc
# OUT2=hello_x86
# OUT=hello_arm
obj-m:= hello.o
# $(OUT): hello.o
# 	echo "This line will always print, because the file hello does not exist."
# 	$(CC) hello.o -o $(OUT)
# hello.o: hello.S
# 	$(CC) -c hello.S -o hello.o
# hello.S: hello.i
# 	$(CC) -S hello.i -o hello.S
# hello.i: hello.c
# 	$(CC) -E hello.c -o hello.i

# clean:
# 	rm -rf *.o *.i *.S hello_x86 hello_arm
