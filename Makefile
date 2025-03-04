# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Output executable
TARGET = hospital_system

# Source files
SRC = main.cpp proj.cpp
OBJ = $(SRC:.cpp=.o)

# Default rule: Compile and link
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile .cpp files to .o files
%.o: %.cpp proj.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)
