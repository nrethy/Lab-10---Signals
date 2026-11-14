/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by:
 * Noah Rethwisch 
 * Brief summary of modifications:
 * added a handler for SIGSEGV
 */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigsegv(int sig){
    printf("Segmentation Fault Intercepted\n");
}

int main (int argc, char* argv[]) {
    signal(SIGSEGV, handle_sigsegv);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}
