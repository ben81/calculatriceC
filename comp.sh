gcc -ansi -Wall -c  addi.c
gcc -ansi -Wall -c  sous.c
gcc -ansi -Wall -c  multi.c
gcc -ansi -Wall -c  nbrdef.c
gcc -ansi -Wall -c  projet.c 
gcc -ansi -Wall -c  divi.c
gcc -ansi -Wall -c  primo.c
gcc -ansi -Wall -c  fibo.c
gcc -ansi -Wall -c  facto.c
gcc addi.o sous.o multi.o nbrdef.o projet.o divi.o primo.o fibo.o facto.o -o cal -lm