.PHONY: all clean

CC = gcc
CFLAGS = -Wall -Wextra -O3 

# We use -mconsole here so the terminal stays visible for input
LDFLAGS = -static -lmingw32 -lSDL2main -lSDL2 \
          -mconsole -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 \
          -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi \
          -lversion -luuid -lhid -static-libgcc

TARGET = plot.exe
SRC = plot.c tinyexpr.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	del /f $(TARGET)