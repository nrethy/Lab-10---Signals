/**
 * File: recv_signal.c
 * Modified by: Noah Rethwisch
 * Brief summary of program:
 * uses sigaction to register a handler for sigusr1
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void signal_handle(int sig, siginfo_t *siginfo, void *test){
    printf("The sival_int is %d\n", siginfo->si_value.sival_int);
}

int main(){
    struct sigaction signalinfo;
    signalinfo.sa_sigaction = signal_handle;
    signalinfo.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &signalinfo, NULL);
    printf("My pid is %d\n", getpid());
    while(1){
        sleep(1);
    }
}
