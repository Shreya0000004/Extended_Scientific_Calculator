# Makefile for Calculator program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = main.cpp calculator.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = scalculator

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) -lm

# Compiling
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(EXEC) $(OBJS)

# Phony target to run the program
run: $(EXEC)
	./$(EXEC)

