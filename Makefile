# Compiler
CC = g++

# Object files
OBJS = Player.o Board.o Card.o Cross.o Plot.o Catan.o demo.o

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic -std=c++11

# Target
TARGET = demo

all: $(TARGET)

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


# Link object files to executable

$(TARGET): $(OBJS) Definition.hpp
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)