all: clean compile run

compile: main.c
	@echo "\nCompiling..."
	@gcc -c main.c
	@gcc main.o -lm -o tavuk.out

run: compile
	@echo "\nRunning the tests....\n"
	./tavuk.out

clean:
	@echo "\nRemoving compiled files...\n"
	@rm -f *.o
	@rm -f *.out
	@rm -f *.exe
#	@rm -f *.txt
