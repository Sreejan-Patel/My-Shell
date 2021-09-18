CC=gcc
LIBS=-lm
TARGET=My_Shell
all : main.c globals.c processer/*.c utils/*.c commands/*.c
	$(CC) -o $(TARGET) main.c globals.c processer/*.c utils/*.c commands/*.c $(LIBS)