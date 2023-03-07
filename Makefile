EXEC:= pacman
default:= $(EXEC)
CC:=g++

pacman: main.o pacman.o
	$(CC) $(CFLAGS) -o $(EXEC) main.o pacman.o
clean:
	rm -f *.o $(EXEC)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $<
