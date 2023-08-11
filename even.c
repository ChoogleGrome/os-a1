#include <stdio.h>
#include <signal.h>

void sig_int_handler() {
    printf("Yeah!\n");
    return;
}

void sig_hup_handler() {
    printf("Ouch!\n");
    return;
}

int main(int argc, char *argv[]) {
    signal(SIGINT, sig_int_handler);
    signal(SIGHUP, sig_hup_handler);

    if (argc != 2) {
        printf("INCORRECT NUMBER OF ARGUMENTS\n");
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Please enter a positive integer\n");
        return 1;
    }

    for (int i = 1; n > 0; i++) {
        if (i % 2 == 0) {
            sleep(5);
            printf("%d\n", i);
            n--;
        }
    }

    return 0;
}
