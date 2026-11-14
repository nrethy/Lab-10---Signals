/*
** Filename: signal_sigaction.c
** Author: Noah Rethwisch
** Date: 11/13/2026
** Description: use sigaction to register a handler for SIGUSR1
** The signal SIGUSR1 can be sent by running kill -USR1 pid
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Handles the signal when recived, and prints PID
void handle_signal(int sig, siginfo_t *siginfo, void *test) {
    printf("PID of process %d\n", siginfo->si_pid);
}

int main() {
    // initialize signalinfo
    struct sigaction signalinfo;
    signalinfo.sa_sigaction = handle_signal;
    signalinfo.sa_flags = SA_SIGINFO;
    // start waiting for SIGUSR1
    sigaction(SIGUSR1, &signalinfo, NULL);
    printf("My PID is %d\n", getpid());
    while (1) {
        sleep(1);
    }
}
