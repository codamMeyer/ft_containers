CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98

TEST_FLAGS= -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak -Wl,-rpath=/usr/local/lib -lgtest -lgtest_main -lpthread
TEST_CRITERION_FLAG= -lcriterion -L /usr/local/lib -I /usr/local/include -std=c++11 -Wl,-rpath=/usr/local/lib

NAME=vector

HEADER_FILES = 	Vector.hpp

TEST=$(NAME)Test

TEST_FILES=test/test.cpp

TEST_CRITERION_FILES=test/testCriterion.cpp

all: test

test: $(HEADER_FILES) $(TEST_FILES)
	@g++ $(TEST_FLAGS) $(SRC_FILES) $(TEST_FILES) -o $(TEST)

criterionTest: $(HEADER_FILES) $(TEST_CRITERION_FILES)
	@g++ -o $(TEST) $(TEST_CRITERION_FILES) $(TEST_CRITERION_FLAG)

run: all
	./$(TEST)

clean:

re: fclean all

fclean: clean
	rm -f $(TEST)

.PHONY: all clean fclean re test
