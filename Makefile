cppfiles := $(wildcard *.cpp)
default: 
	g++ -std=c++11 $(cppfiles) -o main
clean:
	rm -f *.o main
	
