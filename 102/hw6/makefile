all: clean compile run

compile: a.c
	@echo "\nCompiling..."
	@gcc -c a.c
	@gcc a.o -o tavuk.out

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
	@gcc -c -g a.c
	@gcc main.o -o main-gdb.exe