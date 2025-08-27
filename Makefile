# NOTE: Because C is very much an old and designed by committee language (with a few implementations) there is no 'official' build system
# All build systems suck, but maybe Make is one of the least bad, and it will be what you will use for this class

# This is a 'target'
build:
	gcc -g main.c -o program.x

run: build # You can add dependencies, these run before the target
	./program.x


# You will often see something like this:
program: main.o util.o
	gcc -o program main.o util.o

main.o: main.c util.h
	gcc -c main.c

util.o: util.c util.h
	gcc -c util.c

# This is an incremental build... make will check if we need to recompile a given file
# (if we've edited it or a header file that is included)

# NOTE: I personally do not like this... I've had too many bugs due to incremental build systems
# I prefer one single compilation unit

# Variables too:
CC 				= gcc
CFLAGS 		= -Wall -g
SRC_FILES = main.c

build_with_variables:
	$(CC) $(CFLAGS) $(SRC_FILES) -o program.x

# Can run your own arbitrary scripts too:
# Its really just an automation tool and you will find that people use make for many other things
# than compiling your C program
run_script:
	ls
	./count_lines.sh
