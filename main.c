#include <stdio.h>
#include "node.h"


int main() {

    float* weightCheck = randomWeights(MAX_NODES);
    printf("Create 480000 weights: %ld", sizeof(pNode)  * MAX_NODES);

    pNode n1= createNode(INPUT_NODES,input);
    pNode n2= createNode(HIDDEN_NODES,hidden);
    pNode n3= createNode(HIDDEN_NODES,hidden);
    pNode n4= createNode(OUTPUT_NODES,output);

    pLayer l1 = createLayer(INPUT_NODES,input,NULL);
    pLayer l2= createLayer(HIDDEN_NODES,hidden,l1);
    pLayer l3= createLayer(HIDDEN_NODES, hidden,l2);
    pLayer L4= createLayer(OUTPUT_NODES,output, l3);

    freeNode(n1);
    freeNode(n2);
    freeNode(n3);
    freeNode(n4);
    return 0;
}
