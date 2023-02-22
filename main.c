#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "node.h"

void sigint_handler(int signum) {
    printf("Received signal %d (SIGINT)\nClean up linkedList", signum);
    exit(1);
}

int main() {



}
