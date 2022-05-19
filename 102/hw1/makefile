all: clean compile run

compile: main.c utils.h
	@echo "\nCompiling..."
	@gcc -c main.c utils.c
	@gcc main.o utils.o -o tavuk.out

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
	@gcc -c -g main.c utils.c
	@gcc main.o utils.o -o main-gdb.exe