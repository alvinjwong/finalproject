CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic

SOURCES = wikigraph.cpp wikipage.cpp wikiUnitTest.cpp

HEADERS = wikigraph.h wikipage.h

TARGET = wikiUnitTest

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
