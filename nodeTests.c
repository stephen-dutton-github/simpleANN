//
// Created by sdutton on 15.02.23.
//


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "node.h"
#include "nodeTests.h"

int main(int argc, char **argv){
    runNodeTests();
   /* runLayerTests();
    runNetworkTests();*/
}

typedef int (*printHandler)(const char*,...);

void runNodeTests(){

    printHandler _p = printf;

    //input layer (layer 0)
    pNode n0= createNode(INPUT_NODES,0,input);

    //hidden layer (layer 1)
    pNode n1= createNode(HIDDEN_NODES,INPUT_NODES,hidden);
    int count =0;
    for(int i=0; i < HIDDEN_NODES; i++){
        for(int j=0; j < INPUT_NODES; j++)
        {
            count++;
            if(count % 240000 == 0)
                _p("node %d, weight %d, %g \n",i, j, n1[i].weights[j]);
        }
    }



    pLayer l0 = createLayer(INPUT_NODES,input,NULL);
    pLayer l1= createLayer(HIDDEN_NODES,hidden,l0);
    pLayer l2= createLayer(HIDDEN_NODES, hidden,l1);
    //pLayer L3= createLayer(OUTPUT_NODES,output, l2);

    count=0;
    for(int i=0; i < INPUT_NODES ; i++){
        if(count++ % 48000) {
            _p("layer 0 (input) node %d, no weights, output %g \n", i, l0->nodes[i]->output);
        }
    }

    count=0;
    for(int i=0; i < HIDDEN_NODES ; i++)
    {
        for(int j=0; j < INPUT_NODES ; j++){
            if(count++ % 480000)
            {
                _p("layer 1 (hidden) node %d, node input %g, weights %g \n", i, l1->nodes[i]->inputs[j], l1->nodes[i]->weights[i]);
            }
        }
    }

    for(int i=0; i < HIDDEN_NODES; i++)
    {
        _p("Freed weights at %ld\n", n1[i].weights);
        free((void*)n1[i].weights);
    }

    _p("Freed nodes at %ld \n", n1);
    free(n1);
    free(n0);

    /*
    freeNode(n2);
    freeNode(n3);
    freeNode(n4);
    */
    //return 0;
}

void runLayerTests(){

}

void runNetworkTests(){

}