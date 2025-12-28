
.PHONY: all clean

# Variables
CC=gcc
CFLAGS = -Wall -Wextra -g 
LDFLAGS= -lmingw32 -lSDL2main -lSDL2 -mconsole
TARGET= plot.exe
SRC= plot.c

# The "all" rule - what happens when you just type 'make'
all : $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
	

# a "CLEAN" RULE TO DELETE THE exe and start fresh
clean:
	del /f $(TARGET)