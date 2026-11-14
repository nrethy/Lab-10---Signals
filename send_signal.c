/**
 * File: send_signal.c
 * Modified by: Noah Rethwisch
 * Brief summary of program:
 * send SIGUSR1 and a random integer 
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){
    srand(time(NULL));
    union sigval sival;
    sival.sival_int = rand() % 100;
    printf("The si_value is %d\n", sival.sival_int);
    pid_t pid = atoi(argv[1]);
    sigqueue(pid, SIGUSR1, sival);
    return 0;
}
