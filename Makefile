main: clean
	g++ main.cpp utils.cpp graph.cpp unionFind.cpp -o main

clean:
	rm -f main