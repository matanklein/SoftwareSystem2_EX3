# /*
#    email- matank214@gmail.com
# */

# Compiler
CC = g++

# Object files
OBJS = Player.o Board.o Card.o Cross.o Plot.o Catan.o demo.o

# Compiler flags
CFLAGS = -g -Wall -Wextra -pedantic -std=c++11

# Target
TARGET = demo

all: $(TARGET)

catan : $(TARGET)
	./$(TARGET)

Player.o: Player.cpp Player.hpp
	$(CC) $(CFLAGS) -c Player.cpp

Cross.o: Cross.cpp Cross.hpp
	$(CC) $(CFLAGS) -c Cross.cpp

Plot.o: Plot.cpp Plot.hpp
	$(CC) $(CFLAGS) -c Plot.cpp

Board.o: Board.cpp Board.hpp
	$(CC) $(CFLAGS) -c Board.cpp

Card.o: Card.cpp Card.hpp
	$(CC) $(CFLAGS) -c Card.cpp

Catan.o: Catan.cpp Catan.hpp
	$(CC) $(CFLAGS) -c Catan.cpp

demo.o: demo.cpp
	$(CC) $(CFLAGS) -c demo.cpp

Test.o: Test.cpp
	$(CC) $(CFLAGS) -c Test.cpp

TestCounter.o: TestCounter.cpp
	$(CC) $(CFLAGS) -c TestCounter.cpp

test: Test.o TestCounter.o Player.o Board.o Card.o Cross.o Plot.o Catan.o
	$(CC) $(CFLAGS) -o test Test.o TestCounter.o Player.o Board.o Card.o Cross.o Plot.o Catan.o


valgrind: $(TARGET)
	valgrind --leak-check=full -s ./$(TARGET)

# Link object files to executable
$(TARGET): $(OBJS) Definition.hpp
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET) Test.o TestCounter.o test