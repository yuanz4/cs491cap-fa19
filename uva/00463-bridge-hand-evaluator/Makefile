TESTS:=$(wildcard tests/*.in)

.PHONY: tests
tests: main $(TESTS)
	$(foreach var, $(TESTS), ./main < $(var);)

main: main.cpp
	g++ -o main main.cpp

clean:
	-rm -f *.o main
