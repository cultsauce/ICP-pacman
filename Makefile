CFLAGS:= -pedantic
EXEC:= pacman
default:= $(EXEC)
CC:=g++

pacman: $(EXEC).o main.o
	$(CC) $(CFLAGS) -o $(EXEC) main.o $(EXEC).o
clean:
	rm -f *.o $(EXEC)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $<
