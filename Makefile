# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# source files
SOURCES = main.cpp \
	      Rational.cpp \
		  TestRunner.cpp \
		  RationalTests.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Target executable
TARGET = run_tests

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the tests
test: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean test 