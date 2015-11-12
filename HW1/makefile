all: useWalker walk

useWalker: useWalker.o Walker.o
	g++ -g -Wall -o useWalker useWalker.o Walker.o

walk: walk.o Walker.o
	g++ -g -Wall -o walk walk.o Walker.o

walk.o: walk.cpp
	g++ -Wall -c walk.cpp

useWalker.o: useWalker.cpp
	g++ -g -Wall -c useWalker.cpp

Walker.o: Walker.cpp Walker.h
	g++ -g -Wall -c Walker.cpp

clean:
	rm -rf *.o walk useWalker
