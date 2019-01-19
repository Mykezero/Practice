CPPUTEST_HOME = /tools/cpputest-3.8

bin 		= ./bin
dirs 		= bin out
files 		= .gcda .gcno .o

CPP 		= g++ --coverage
CFLAGS  	= -I$(CPPUTEST_HOME)/include -Isrc/
LDFLAGS 	= --coverage -L$(CPPUTEST_HOME)/lib -lCppUTest

all: clean main
main:
	$(CPP) $(CFLAGS) src/*.c $(LDFLAGS) -o $(bin)/$@
	$(bin)/main
clean:
	$(foreach dir, $(dirs), rm -rf $(dir)/*;)
	$(foreach file, $(files), find . -type f -regex '.*\$(file)' -delete;)
test:
	$(CPP) $(CFLAGS) -D TEST src/*.c tests/*.cpp $(LDFLAGS) -o $(bin)/$@
	$(bin)/test
report:  
	lcov --capture --directory . --output-file out/coverage.info
	genhtml out/coverage.info --output-directory out
	xdg-open out/index.html