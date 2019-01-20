CPPUTEST_HOME = /tools/cpputest-3.8

bin 		= ./bin
dirs 		= bin out
files 		= .gcda .gcno .o

CPP 		= g++ -O0 -g -u -fno-exceptions -fno-inline -fprofile-arcs -ftest-coverage
CFLAGS  	= -I$(CPPUTEST_HOME)/include -Isrc/ --coverage
LDFLAGS 	= -L$(CPPUTEST_HOME)/lib -lCppUTest --coverage

all: main
main:
	$(CPP) $(CFLAGS) src/*.c $(LDFLAGS) -o $(bin)/$@
	$(bin)/main
test: clean
	$(CPP) $(CFLAGS) -D TEST src/*.c tests/*.cpp $(LDFLAGS) -o $(bin)/$@
	$(bin)/test
clean:
	$(foreach dir, $(dirs), rm -rf $(dir)/*;)
	$(foreach file, $(files), find . -type f -regex '.*\$(file)' -delete;)
cover: 
	lcov --rc lcov_branch_coverage=1 --capture --directory . --output-file out/coverage.info
report: cover
	genhtml --branch-coverage out/coverage.info --output-directory out
	xdg-open out/index.html