CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98

TEST_FLAGS= -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak -Wl,-rpath=/usr/local/lib -lgtest -lgtest_main -lpthread -ggdb
TEST_CRITERION_FLAG= -lcriterion -L /usr/local/lib -I /usr/local/include -std=c++11 -Wl,-rpath=/usr/local/lib

NAME=vector

HEADER_FILES=Vector.hpp

TEST=$(NAME)Test

TEST_FILES= 							\
	test/vector.test.cpp				\
	test/vectorIterator.test.cpp		\

all: test

test: $(HEADER_FILES) $(TEST_FILES)
	@g++ $(TEST_FLAGS) $(SRC_FILES) $(TEST_FILES) -o $(TEST)

run: all
	./$(TEST)

clean:

re: fclean all

fclean: clean
	rm -f $(TEST)

.PHONY: all clean fclean re test
