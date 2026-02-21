.PHONY: all clean

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -O3 

# We use -mconsole here so the terminal stays visible for input
LIBS = -lmingw32 -lSDL2main -lSDL2 -mconsole -lm -ldinput8 -ldxguid \
       -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 \
       -lshell32 -lsetupapi -lversion -luuid -lhid

LDFLAGS = -static -static-libgcc

TARGET = plot.exe
SRC = plot.c tinyexpr.c
OBJS = $(SRC:.c=.o) # plot.o tinyexpr.o

# The "all" rule
all: $(TARGET)

# target : dependencies
#code

# Linking: combines .o files to final .exe
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS) $(LIBS)

# Compilation Step: Each .c becomes a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup rule
clean:
	del /f $(OBJS) $(TARGET)