# * Use g++ -v to debug path errors. 
# * Common causes for unreferenced errors from ld: 
#	 https://latedev.wordpress.com/2014/04/22/common-c-error-messages-2-unresolved-reference/

TERMBOX_HOME = ../tools/termbox/usr/local

bin 		= ./bin
dirs 		= bin out
files 		= .o

CXX 		= gcc -Wl,-R$(TERMBOX_HOME)/lib
CXXFLAGS  	= -I$(TERMBOX_HOME)/include -Isrc/
LDFLAGS 	= -L$(TERMBOX_HOME)/lib
LDLIBS		= -ltermbox

all: main
main:
	mkdir -p $(dirs)
	@$(CXX) $(CXXFLAGS) $(LDLIBS) src/*.c $(LDFLAGS) $(LDLIBS) -o $(bin)/$@
	$(bin)/main
test: clean
	@$(CXX) $(CXXFLAGS) src/*.c $(LDFLAGS) $(LDLIBS) -o $(bin)/$@
	-$(bin)/test
clean:
	@$(foreach dir, $(dirs), rm -rf $(dir)/*;)
	@$(foreach file, $(files), find . -type f -regex '.*\$(file)' -delete;)