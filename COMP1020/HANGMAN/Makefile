hangman: my_string.o dictionary.o vector.o String.o Boolean.h filereader.o
	gcc -g hangman.c my_string.o dictionary.o vector.o String.o filereader.o -o hangman
dictionary:
	gcc -c -g dictionary.c -o dictionary.o
vector:
	gcc -c -g vector.c -o vector.o
filereader:
	gcc -c -g filereader.c -o filereader.o

unit_test: my_string.o unit_test.o test_def.o String.o
	gcc -g unit_test.o test_def.o my_string.o String.o -o unit_test
unit_test_o: unit_test.c unit_test.h my_string.h
	gcc -c unit_test.c -o unit_test.o
test_def_o: test_def.c test_def.h my_string.h
	gcc -c test_def.c -o test_def.o
link-main: main.o my_string.o String.o Boolean.h
	gcc -g main.o my_string.o String.o Boolean.h -o main
create-main: main.c
	gcc -c main.c -o main.o
create-my_string: String.o my_string.c my_string.h
	gcc -c -g -Wall my_string.c -o my_string.o
create-String: String.c String.h Boolean.h
	gcc -c -g String.c -o String.o
del:
	rm *.o
	rm main



