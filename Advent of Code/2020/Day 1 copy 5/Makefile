CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
LIBRARY_DIR = ../../library
TARGET = day_1_solution_2020

LIBRARY_SRC = $(wildcard $(LIBRARY_DIR)/*.cpp)

LIBRARY_OBJ = $(LIBRARY_SRC:.cpp=.o)

$(TARGET): main.cpp $(LIBRARY_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp $(LIBRARY_OBJ)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(LIBRARY_OBJ)
