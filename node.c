//
// Created by sdutton on 14.02.23.
//
#include <stdlib.h>
#include "string.h"
#include "node.h"
#include "malloc.h"
#include "math.h"


float* randomWeights(int count){
    float k=0.0;
    size_t fsize = sizeof(float);
    float* results = malloc(fsize * count);
    for(int i=0;i < count; i++){
        results[i] = (float) rand() / RAND_MAX;
    }
    return results;
}

pNode createNode(unsigned int quantity, unsigned int numberOfInputs, enum layerTypeEnum type ){
    size_t nodeSize = sizeof (struct nodeDef);

    pNode startNode = malloc(nodeSize * quantity);
    memset(startNode,0, nodeSize * quantity);
    float initOutput = 0.0f;
    for(unsigned i=0;i < quantity; i++){

        switch(type){
            case input:
                startNode[i].output=&initOutput;
                break;
            case hidden:
            case output:
                startNode[i].weights=randomWeights(numberOfInputs);
            break;
        }
    }
    return startNode;
};

void freeNode(pNode node){
    free(node->weights);
}

pLayer createLayer(unsigned int nodeCount, enum  layerTypeEnum lt, pLayer previousLayer){

    int previousLayerCount = 0;
    pLayer layer= malloc(sizeof(struct layerDef));

    layer->nodes = createNode(nodeCount, previousLayer ? previousLayer->nodeCount : 0, lt);
    layer->nodeCount = nodeCount;
    layer->_layerType = lt;


    if(previousLayer){

            for(unsigned i=0;i < nodeCount; i++){
                for(unsigned int j=0; j < previousLayer->nodeCount; j++){
                    layer->nodes[i]->inputs[j] = previousLayer->nodes[j]->output;
            }
        }
    }
};

pNetwork createNetwork(char* restrict name, pLayer* layers){

};


