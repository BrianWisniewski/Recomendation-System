CXX = g++
OPTIONS = -Wall -std=c++11
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp BooksList.cpp
	$(CXX) $(OPTIONS) main.cpp BooksList.cpp -o $(PROGRAM) 

clean:
	rm -f $(PROGRAM)

test: 
	g++ -Wall -std=c++11 test.cpp -o test

testRun: test
	./test