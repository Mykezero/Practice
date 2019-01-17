src = $(wildcard src/*.c)
obj = $(src:.c=.o)
bin = ./bin


test = $(wildcard test/*.c)
test_obj = $(test:.c=.o)

C = gcc
CFLAGS = --coverage
LDFLAGS = --coverage

all: clean main tests run

main: $(obj)
	$(C) $(CFLAGS) -o $(bin)/$@ $^ $(LDFLAGS)

tests: $(test_obj)
	$(C) $(CFLAGS) -o $(bin)/$@ $^ $(LDFLAGS)

clean:
	rm -f $(obj) main
	rm -f $(test_obj) runner

run: 
	$(bin)/tests