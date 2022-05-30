CC = gcc
EXEC = prog
all : prog

$(EXEC) : dict.o
	$(CC) -o prog  dict.o


# main.o : main.c
#	$(CC)  -o main.o -c main.c -Wall

dict.o : load_dic.c
		$(CC)  -o dict.o -c load_dic.c -Wall
