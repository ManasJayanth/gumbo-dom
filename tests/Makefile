CC := g++
GUMBO_INCLUDE_FLAGS := `pkg-config --cflags gumbo`
GUMBO_LIBRARY_FLAGS := `pkg-config --libs gumbo`
GTEST_ROOT := "I `../googletest/googletest/include/`"
TESTS_DIR := "./tests"
all: tests_main.o test_utils.o gumbo_dom.o
	${CC} \
	tests_main.o \
	test_utils.o \
	gumbo_dom.o \
	-o parser_tests ${GUMBO_LIBRARY_FLAGS}

tests_main.o: ${TESTS}/main.cc test_utils.h
	${CC} -I . ${GUMBO_INCLUDE_FLAGS} -I "../" -c tests_main.cc

test_utils.o: test_utils.cc test_utils.h
	${CC} -I . -c test_utils.cc

tests: ${TESTS_DIR}/main.cc
	${CC} tests_main.o \
	-o tests_main -I "../googletest/googletest/include/"
clean:
	rm -rf *.o
	rm parser_tests
