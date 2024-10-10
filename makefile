CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
DJATH = dijkstra_algorithm
FYATH = floyd_algorithm
INSS = input_streamline

SRCS = main.cpp \
		$(DJATH)/dijkstra_algorithm.cpp \
		$(FYATH)/floyd_algorithm.cpp \
		$(INSS)/input_streamline.cpp 

EXECUTABLE = a.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean