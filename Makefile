all:	build build_logint build_sorts link run
build_logint:
		g++ -c logint/logint.cpp -ggdb3
build_sorts:
		g++ -c sorts/sorts.cpp -ggdb3
build:
		g++ -c main.cpp  -ggdb3
link:
		g++ main.o logint.o sorts.o -o main -lsfml-graphics -lsfml-window -lsfml-system
run:
		./main