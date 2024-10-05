CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type -Werror=uninitialized -Wno-sign-compare -I.

HEADERS = analytical-model.hpp pq.hpp FIFO.hpp customer.hpp
TEST_SOURCES = test/analytical-model-test1.cpp test/customer-test1.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
MAIN_OBJECTS = main.o analytical-model.o pq.o FIFO.o customer.o
TEST_TARGETS = $(TEST_SOURCES:.cpp=.out)
MAIN_TARGET = main_executable

all: $(TEST_TARGETS) $(MAIN_TARGET)

$(TEST_TARGETS): %.out: %.o analytical-model.o pq.o FIFO.o customer.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

run-test: $(TEST_TARGETS)
	for test in $(TEST_TARGETS); do ./$$test; done

main: $(MAIN_TARGET)
	./$(MAIN_TARGET)

test/%.o: test/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

analytical-model.o: analytical-model.cpp analytical-model.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

pq.o: pq.cpp pq.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

customer.o: customer.cpp customer.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

FIFO.o: FIFO.cpp FIFO.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TEST_OBJECTS) $(MAIN_OBJECTS) $(TEST_TARGETS) $(MAIN_TARGET)