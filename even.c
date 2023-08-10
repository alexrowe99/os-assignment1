#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void hup_handler(int sig) {
	printf("/nOuch!");
}

void int_handler(int sig) {
	printf("/nYeah!");
}

int main(int argc, char *argv[]) {
	signal(SIGHUP, hup_handler);
	signal(SIGINT, int_handler);
	int n = atoi(argv[1]);
	for (int i=0;i<n*2;i+=2) {
		printf("%d\n", i);
		sleep(5);
	}
	return (0);
}