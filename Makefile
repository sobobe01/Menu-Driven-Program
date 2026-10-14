CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -O2

membership: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp

run: membership
	./membership

test: membership
	./membership < tests/input.txt | diff -u tests/expected.txt -
	@echo "tests passed"

clean:
	rm -f membership

.PHONY: run test clean
