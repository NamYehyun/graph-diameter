CXX = g++
TARGET = main
OBJECTS = main.o graph.o
CXXFLAGS = -std=c++14 -Wall -O3
LDFLAGS =

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(TARGET) $(OBJECTS) *.html pyplot/*.png __pycache__
