CPPUTEST_HOME = /tools/cpputest-3.8

# Store C source and objects
src = $(wildcard src/*.c)
src_obj = $(src:.c=.o)

# Store CPP source and objects
test = $(wildcard tests/*.cpp)
test_obj = $(test:.cpp=.o)

obj = $(src_obj) $(test_obj)
bin = ./bin

# For compiling the C application code.
CC			= gcc
CFLAGS 		= --coverage
LDFLAGS 	= --coverage -L$(CPPUTEST_HOME)/lib -lCppUTest

# For compiling cpputest with C++
CPP 		= g++
CPPFLAGS  	= -g -Wall -I$(CPPUTEST_HOME)/include

all: clean main test run cover
main: $(src_obj)
	echo $(src_obj)
	$(CC) $(CFLAGS) -o $(bin)/$@ $^ $(LDFLAGS)
test: $(test_obj)
	echo $(test_obj)
	$(CPP) $(CPPFLAGS) -o $(bin)/$@ $^ $(LDFLAGS)
clean:
	rm -f $(obj) $(bin)/test $(bin)/main
run: 
	$(bin)/test
cover:
	# lcov --capture --directory . --output-file out/coverage.info
	# genhtml out/coverage.info --output-directory out