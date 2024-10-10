CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
DJATH = dijkstra_algorithm
INSS = input_streamline

SRCS = main.cpp \
		$(DJATH)/dijkstra_algorithm.cpp \
		$(INSS)/input_streamline.cpp \

EXECUTABLE = output.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean