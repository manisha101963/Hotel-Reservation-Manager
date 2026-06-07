CXX = g++
CXXFLAGS = -Iinclude
SRC = $(wildcard src/*.cpp)
TARGET = hotel.exe

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)