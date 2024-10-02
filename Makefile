CXX = g++
CXXFLAGS = -g -std==c++14 -Wall -Werror=return-type -Werror=uninitialized -Wno-sign-compare

HEADERS = analytical-model.hpp
TEST_OBJECTS = test/analytical-model-test1.o analytical-model.o 
MAIN_OBJECTS = main.o analytical-model.o
TEST_TARGET = test_executable
MAIN_TARGET = main_executable

all: $(TEST_TARGET) $(MAIN_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_TARGET): $(MAIN_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_TARGET)
	./$(TEST_TARGET)

main: $(MAIN_TARGET)
	./$(MAIN_TARGET)

%.o: test/%.cpp $(HEADERS)
	$(CSS) $(CXXFLAGS) -c -o $@ $<

analytical-model.o: analytical-model.cpp analytical-model.hpp
	$(CSS) $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp
	$(CSS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TEST_OBJECTS) $(MAIN_OBJECTS) $(TEST_TARGET) $(MAIN_TARGET)