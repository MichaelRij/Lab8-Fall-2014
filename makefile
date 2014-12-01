CC = g++
OBJ = driver.o memory.o

prog: $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) -c $<

clean: 
	rm *.o prog
