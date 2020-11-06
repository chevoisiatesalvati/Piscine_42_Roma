exe: partie1.o partie2.o partie3.o main.o
	gcc -o lancerPro partie1.o partie2.o partie3.o main.o

main.o: main.c gratteCiel.h
	gcc -Wall -c main.c

partie1.o: partie1.c gratteCiel.h
	gcc -Wall -c partie1.c

partie2.o: partie2.c gratteCiel.h
	gcc -Wall -c partie2.c

partie3.o: partie3.c gratteCiel.h
	gcc -Wall -c partie3.c
