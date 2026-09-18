CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -g
TARGET = my_program
all: $(TARGET)
$(TARGET): my_program.c
$(CC) $(CFLAGS) my_program.c -o $(TARGET)
clean:
rm -f $(TARGET)
.PHONY: all clean