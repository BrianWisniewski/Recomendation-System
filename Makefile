CXX = g++
OPTIONS = -Wall -std=c++11
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) $(data)

$(PROGRAM): main.cpp BookRecommender.cpp
	$(CXX) $(OPTIONS) main.cpp BookRecommender.cpp -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)