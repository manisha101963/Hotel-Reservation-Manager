CXX = g++
CXXFLAGS = -Iinclude
SRC = src/*.cpp
TARGET = hotel

all:
	$(CXX) $(SRC) $(CXXFLAGS) -o $(TARGET)

run:
	./$(TARGET).exe

clean:
	rm -f $(TARGET).exe