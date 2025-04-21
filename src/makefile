CC = g++
OS = $(shell uname)
FLAGS =  -Wall -Werror -Wextra -std=c++20

TARGET = s21_matrix_oop.a
MODULES = $(wildcard modules/*.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(MODULES))

TEST_SRC = $(wildcard tests/*.cpp)
TEST_OBJ = $(patsubst tests/%.cpp, tests/%.o, $(TEST_SRC))
TEST_FLAGS = -lgtest -lgtest_main -pthread

all: clean $(TARGET) test
	
$(TARGET): $(OBJECTS)
	@ar rcs $@ $^

test: $(OBJECTS) $(TEST_OBJ)
	@$(CC) $(FLAGS) -o test $(OBJECTS) $(TEST_OBJ) $(TEST_FLAGS)
	@./test

objects/%.o: modules/%.cpp
	@mkdir -p objects 
	@$(CC) -c $(FLAGS) -I $< -o $@

tests/%.o: tests/%.cpp
	@$(CC) $(FLAGS) $(INCLUDE_DIR) -c $< -o $@

build: $(TARGET)

rebuild: clean $(TARGET)

clean:
	@rm -f $(OBJECTS) $(TEST_OBJ) test $(TARGET)