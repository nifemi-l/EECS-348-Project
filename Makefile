CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = main.cpp nodes.cpp tokens.cpp lexer.cpp parser.cpp interpreter.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
