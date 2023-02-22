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

}

void runLayerTests(){

}

void runNetworkTests(){

}