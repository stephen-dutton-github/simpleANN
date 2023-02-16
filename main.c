#include <stdio.h>
#include "node.h"
int main() {
    float* weightCheck = randomWeights(480000);
    printf("Create 480000 weights: %ld", sizeof(weightCheck));

    return 0;
}
