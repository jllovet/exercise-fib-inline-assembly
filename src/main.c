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
        printf("%ld\n", nth_fibonacci);
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
    long nth_fib = 0;
    asm (
        // AT&T Syntax
        // Operations
        // mov source, destination
        // xadd source, destination -> moves sum of source and destination to the 
        // destination register and the original destination value into the source

        // $0 -> The $ indicates a literal numeric value
        // rax -> Accumulator Register (results of mathematical operations)
        // rcx -> Counter Register (how many times we want to do something)
        // rdx -> Extended Accumulator Register
        "mov $0, %%rdx      \n" // Write the first element of the fib sequence
        "mov $1, %%rax      \n" // Write the second element of the fib sequence
        "mov %0, %%rcx      \n" // Initialize counter to arg passed to asm
        "fib_loop:          \n"
        "xadd %%rdx, %%rax  \n"
        "dec %%rcx          \n"
        "jnz fib_loop       \n"
        "mov %%rax, %1      \n"
        : "=r" (nth_fib) // This will be "returned" (who knows how assembly works anyway?)
        : "r" (n) // This is the "argument" to the assembly "function" (i.e. an operand to the assembly instruction)
        : "rcx", "rdx", "rax" // Now we're clobbering 😭
    );
    return nth_fib;
}