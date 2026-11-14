/**
 * File: signal_alarm.c 
 * Modified by:
 * Noah Rethwisch
 * Brief summary of program:
 * schedules an alarm to be sent after 5 seconds
 */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handle_alarm(int alarm){
    printf("Alarm Signal Recieved\n");
}

int main(){
    signal(SIGALRM, handle_alarm);
    alarm(5);
    pause();
    return 0;
}
