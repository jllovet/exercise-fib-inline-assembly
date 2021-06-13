#include <stdio.h>
#include <stdlib.h>

long fib(long n);

void printUsage(){
    puts("Enter the nth fibonacci number that you'd like to calculate\nUsage: fib n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }
    else {
        long n = atol(argv[1]);
        long nth_fibonacci = fib(n);
        printf("%d\n", nth_fibonacci);
    }
    return EXIT_SUCCESS;
}

long fib(long n) {
    // Calculates the nth fibonacci number
    // TODO: Change from stub that increments to actual multi-line asm

    // Now we're going to do some inline-assembly shit.
    // May God have mercy on our souls.
    // Here be dragons and the City of Dis.
    // Lasciate ogni speranza, voi c'e l'entrate and all that
    asm (
        "incl %0"
        : "=r" (n) // This will be "returned" (who knows how assembly works anyway?)
        : "r" (n) // This is the "argument" to the assembly "function" (i.e. an operand to the assembly instruction)
        : // No registers clobbered! See: https://stackoverflow.com/questions/41899881/what-is-a-clobber/41900500
    );
    return n;
}