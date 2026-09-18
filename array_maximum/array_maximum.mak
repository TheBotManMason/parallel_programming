CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -g
TARGET = array_maximum
all: $(TARGET)
$(TARGET): array_maximum.c
$(CC) $(CFLAGS) array_maximum.c -o $(TARGET)
clean:
rm -f $(TARGET)
.PHONY: all clean