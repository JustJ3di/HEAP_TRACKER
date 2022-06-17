gcc -c -o garbage.o garbage.c -Wall -Wextra
gcc -c -o main.o main.c -Wall -Wextra
gcc -o main main.o garbage.o -Wall -Wextra