CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98

TEST_FLAGS=-Wl,-rpath=/usr/local/lib -lgtest -lgtest_main -lpthread

NAME=vector

HEADER_FILES = 	Vector.hpp

TEST=$(NAME)Test

all: test

test: $(HEADER_FILES) test.cpp
	@g++ $(TEST_FLAGS) $(SRC_FILES) test.cpp -o $(TEST)

run: all
	./$(TEST)

clean:

re: fclean all

fclean: clean
	rm -f $(TEST)

.PHONY: all clean fclean re
