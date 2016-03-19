default:
	g++ -g -c -rdynamic -Wall -Wextra traceback.cpp
	g++ -g -c -rdynamic -Wall -Wextra main.cpp
	g++ -rdynamic -g -Wall -Wextra -o test traceback.o main.o -lbfd

clean:
	rm test
