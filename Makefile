# * Use g++ -v to debug path errors. 
# * Common causes for unreferenced errors from ld: 
#	 https://latedev.wordpress.com/2014/04/22/common-c-error-messages-2-unresolved-reference/

CPPUTEST_HOME = tools/cpputest-3.8
TERMBOX_HOME = tools/termbox/usr/local

bin 		= ./bin
dirs 		= bin out
files 		= .gcda .gcno .o

CXX 		= g++ -O0 -g -u -fno-exceptions -fno-inline -fprofile-arcs -ftest-coverage
CXXFLAGS  	= -I$(CPPUTEST_HOME)/include -I$(TERMBOX_HOME)/include -Isrc/ --coverage
LDFLAGS 	= -L$(CPPUTEST_HOME)/lib -L$(TERMBOX_HOME)/lib --coverage
LDLIBS		= -lCppUTest -ltermbox

all: main
main:
	@$(CXX) $(CXXFLAGS) $(LDLIBS) src/*.c $(LDFLAGS) $(LDLIBS) -o $(bin)/$@
	$(bin)/main
test: clean
	@$(CXX) $(CXXFLAGS) -D CPPUTEST src/*.c tests/*.cpp $(LDFLAGS) $(LDLIBS) -o $(bin)/$@
	-$(bin)/test
clean:
	@$(foreach dir, $(dirs), rm -rf $(dir)/*;)
	@$(foreach file, $(files), find . -type f -regex '.*\$(file)' -delete;)
cover: 
	@lcov --rc lcov_branch_coverage=1 --capture --directory . --output-file out/coverage.info
report: cover
	@genhtml --branch-coverage out/coverage.info --output-directory out
	@xdg-open out/index.html