CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98

TEST_FLAGS= -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak -Wl,-rpath=/usr/local/lib -L/home/mmeyer -lgtest -lgtest_main -lpthread -ggdb
GDB_TEST_FLAGS= -Wall -Werror -Wextra -Wl,-rpath=/usr/local/lib -lgtest -lgtest_main -lpthread -ggdb3 -O0

NAME=vector

HEADER_FILES=			\
	Vector.hpp			\
	VectorIterator.hpp 	\

TEST=$(NAME)Test

TEST_FILES= 							\
	test/vector.test.cpp				\
	test/vectorIterator.test.cpp		\

all: test

test: $(HEADER_FILES) $(TEST_FILES)
	@g++ $(TEST_FLAGS) $(SRC_FILES) $(TEST_FILES) -o $(TEST) && ./$(TEST)

debug: $(HEADER_FILES) $(TEST_FILES)
	@g++ $(GDB_TEST_FLAGS) $(SRC_FILES) $(TEST_FILES) -o $(TEST)

run: all
	./$(TEST)

clean:

re: fclean all

fclean: clean
	rm -f $(TEST)

.PHONY: all clean fclean re test
