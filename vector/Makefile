CC=clang++
FLAGS=-Wall -Werror -Wextra -I../

CFLAGS= $(FLAGS) -std=c++98
GTEST_INCLUDE=-I/Users/mmeyer/Desktop/googletest-release-1.8.0/googletest/include
TEST_MAC= -Wall -Werror -Wextra $(GTEST_INCLUDE) -L/Users/mmeyer/Desktop/googletest-release-1.8.0/googletest -lgtest -lgtest_main

TEST_FLAGS= $(FLAGS) -fsanitize=address -fsanitize=leak -Wl,-rpath=/usr/local/lib -L/home/mmeyer -lgtest -lgtest_main -lpthread -ggdb
GDB_TEST_FLAGS= $(FLAGS) -Wl,-rpath=/usr/local/lib -lgtest -lgtest_main -lpthread -ggdb3 -O0

NAME=vector

HEADER_FILES=						\
	Vector.hpp						\
	VectorIterator.hpp 				\

TEST=$(NAME)Test

TEST_FILES= 							\
	test/vector.test.cpp				\
	test/vectorIterator.test.cpp		\

all: test

test: $(HEADER_FILES) $(TEST_FILES)
	@g++ $(TEST_FLAGS) $(SRC_FILES) $(TEST_FILES) -o $(TEST) && ./$(TEST)

testMac: $(HEADER_FILES) $(TEST_FILES)
	@g++ $(TEST_MAC) $(SRC_FILES) $(TEST_FILES) -o $(TEST)


debug: $(HEADER_FILES) $(TEST_FILES)
	@g++ $(GDB_TEST_FLAGS) $(SRC_FILES) $(TEST_FILES) -o $(TEST)


run: all
	./$(TEST)

clean:

re: fclean all

fclean: clean
	rm -f $(TEST)

.PHONY: all clean fclean re test
