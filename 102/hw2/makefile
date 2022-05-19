all: clean compile run

compile: main.c util.h
	@echo "\nCompiling..."
	@gcc -c main.c utils.c
	@gcc main.o util.o -o tavuk.out

run: compile
	@echo "\nRunning the tests....\n"
	./tavuk.out

clean:
	@echo "\nRemoving compiled files...\n"
	@rm -f *.o
	@rm -f *.out
	@rm -f *.exe
#	@rm -f *.txt

gdb:
	@echo "\nCompiling for debugging..."
	@gcc -c -g main.c util.c
	@gcc main.o util.o -o main-gdb.exe