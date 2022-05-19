all: clean compile run

compile: main.c
	@echo "\nCompiling..."
	@gcc main.c -o main.o

run: compile
	@echo "\nRunning the tests....\n"
	./main.o

clean:
	@echo "\nRemoving compiled files...\n"
	@rm -f *.o