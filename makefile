
.PHONY: all test clean coverage
CFLAGS=-Wall -Werror

all: main

main: main.o
	g++ ${CFLAGS} $^ -o main

test: testsuite
	@./testsuite

coverage: CFLAGS=-Wall -Werror -fprofile-arcs -ftest-coverage
coverage: clean testsuite
	@./testsuite
	gcov -r test_main.cpp

testsuite: test_main.o
	g++ ${CFLAGS} $^ -o testsuite

main.o: main.cpp list.h list.hpp
	g++ ${CFLAGS} -c main.cpp

test_main.o: test_main.cpp
	g++ ${CFLAGS} -c test_main.cpp

clean:
	-@rm -f main testsuite
	-@rm -f *.o
	-@rm -f *.gcov *.gcno *.gcda

