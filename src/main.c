#include <stdio.h>
#include <stdlib.h>

void printUsage(){
    puts("Enter the nth fibonacci number that you'd like to calculate\nUsage: fib n\n");
}

int main(int argc, char** argv) {
    if (argc == 1) {
        printUsage();
    }
    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }
    else {
        int n = atoi(argv[1]);
        printf("%d\n", n);
    }
    return EXIT_SUCCESS;
}
