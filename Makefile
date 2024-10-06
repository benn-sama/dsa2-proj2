HEADERS = analytical-model.hpp pq.hpp FIFO.hpp customer.hpp simulation.hpp
TEST_SOURCES = test/analytical-model-test1.cpp test/customer-test1.cpp test/fifo-test1.cpp test/pq-test1.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
MAIN_OBJECTS = main.o analytical-model.o pq.o FIFO.o customer.o simulation.o
TEST_TARGETS = $(TEST_SOURCES:.cpp=.out)
MAIN_TARGET = main_executable

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I.

.PHONY: all run-test main clean

all: $(TEST_TARGETS) $(MAIN_TARGET)

$(TEST_TARGETS): %.out: %.o analytical-model.o pq.o FIFO.o customer.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run-test: $(TEST_TARGETS)
	for test in $(TEST_TARGETS); do ./$$test; done

main: $(MAIN_TARGET)

clean:
	rm -f $(TEST_OBJECTS) $(TEST_TARGETS) $(MAIN_OBJECTS) $(MAIN_TARGET)