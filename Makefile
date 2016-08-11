CXX := g++
SOURCE_DIR := .
TESTS_DIR := ./tests
GUMBO_INCLUDE_FLAGS := `pkg-config --cflags gumbo`
GUMBO_LIBRARY_FLAGS := `pkg-config --libs gumbo`

# Points to the root of Google Test, relative to where this file is.
GTEST_DIR = ./deps/googletest/googletest

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Flags passed to the preprocessor.
GTESTCPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
GTESTCXXFLAGS += -g -Wall -Wextra  -pthread

# Builds gtest.a and gtest_main.a.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(GTESTCPPFLAGS) -I$(GTEST_DIR) $(GTESTCXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(GTESTCPPFLAGS) -I$(GTEST_DIR) $(GTESTCXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf *.o
	rm parser
	rm -f $(TESTS) gtest.a gtest_main.a *.o
	rm $(ALL) $(ALL_TESTS)

hw.o : $(SOURCE_DIR)/hw.cc $(SOURCE_DIR)/hw.h
	$(CXX) $(GTESTCPPFLAGS) -c $(SOURCE_DIR)/hw.cc

hw_unittests.o : ${TESTS_DIR}/hw_unittests.cc \
                     $(SOURCE_DIR)/hw.h $(GTEST_HEADERS)
	$(CXX) $(GTESTCPPFLAGS) -c $(TESTS_DIR)/hw_unittests.cc


utils.o: ${SOURCE_DIR}/utils.cc utils.h
	$(CXX) -I . -c utils.cc

utils_unittests.o: ${TESTS_DIR}/utils_unittests.cc  ${SOURCE_DIR}/utils.h
	$(CXX) $(GTESTCPPFLAGS) -c $(TESTS_DIR)/utils_unittests.cc

clean_html.o: ${SOURCE_DIR}/clean_html.cc ${SOURCE_DIR}/headers.h 
	$(CXX) -I . ${GUMBO_INCLUDE_FLAGS} -c clean_html.cc

clean_html_unittests.o: ${TESTS_DIR}/clean_html_unittests.cc ${SOURCE_DIR}/headers.h
	$(CXX) $(GUMBO_INCLUDE_FLAGS) $(GTESTCPPFLAGS) -c $(TESTS_DIR)/clean_html_unittests.cc

gumbo_dom.o: gumbo_dom.cc gumbo_dom.h
	$(CXX) -I . ${GUMBO_INCLUDE_FLAGS} -c gumbo_dom.cc

gumbo_dom_utils.o: $(SOURCE_DIR)/gumbo_dom_utils.cc $(SOURCE_DIR)/gumbo_dom_utils.h
	$(CXX) -I .  -c gumbo_dom_utils.cc

gumbo_dom_utils_unittests.o: $(TESTS_DIR)/gumbo_dom_utils_unittests.cc
	$(CXX) $(GUMBO_INCLUDE_FLAGS) $(GTESTCPPFLAGS) -c $(TESTS_DIR)/gumbo_dom_utils_unittests.cc

main.o: main.cc headers.h
	$(CXX) -I . $(GTESTCPPFLAGS) $(GUMBO_INCLUDE_FLAGS)  -c main.cc

UNITS := hw.o utils.o clean_html.o gumbo_dom_utils.o #clean_html.o gumbo_dom.o
ALL := ${UNITS} main.o 

all: $(ALL)
	$(CXX) \
	$(ALL) \
	-o parser ${GUMBO_LIBRARY_FLAGS}

ALL_TESTS = hw_unittests.o utils_unittests.o clean_html_unittests.o gumbo_dom_utils_unittests.o
unittests : $(UNITS) $(ALL_TESTS) gtest_main.a
	$(CXX) $(GTESTCPPFLAGS) $(GTESTCXXFLAGS) $(GUMBO_LIBRARY_FLAGS) $^ -o $@

