gcc -c -o garbage.o garbage.c
gcc -c -o main.o main.c
gcc -o main main.o garbage.o