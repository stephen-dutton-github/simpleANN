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
   buildNetworkTests();
   /* runLayerTests();
    runNetworkTests();*/
}

typedef int (*printHandler)(const char*,...);

void buildNetworkTests(){
    printHandler _p = printf;
    _p("Start build network: Layers, 6, Nodes: 484005");
    int layerCount = 6;
    int layersNodeSets[6] = {480000,1000,1000,1000,1000,5};
    pNetwork network = buildNetwork(layerCount,layersNodeSets);
    freeNetwork(network);
}

void runNodeTests(){



}

void runLayerTests(){

}

void runNetworkTests(){

}