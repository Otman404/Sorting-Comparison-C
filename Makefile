CC=gcc  #compiler
TARGET=main #target file name
 
all:
	$(CC) main.c tri.c -o $(TARGET)
 
clean:
	rm *.o $(TARGET)

run:
	$(CC) main.c tri.c tri.h -o $(TARGET) && ./$(TARGET)
