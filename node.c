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

pNode createNode(unsigned int quantity, enum layerTypeEnum type ){
    size_t nodeSize = sizeof (struct nodeDef);

    pNode startNode = malloc(nodeSize * quantity);
    memset(startNode,0, nodeSize * quantity);
    for(unsigned i=0;i < quantity; i++){
        switch(type){
            case hidden:
            case output:
                startNode[i].weights=randomWeights(quantity);
            break;
        }

    }
    return startNode;
};

void freeNode(pNode node){
    free(node->weights);
}

pLayer createLayer(unsigned int nodeCount, enum  layerTypeEnum lt, pLayer previousLayer){

    pLayer layer= malloc(sizeof(struct layerDef));
    layer->nodes = createNode(nodeCount,lt);
    layer->nodeCount = nodeCount;
    layer->_layerType = lt;

    for(unsigned i=0;i < nodeCount; i++){

        if(NULL != previousLayer){
            for(unsigned int j=0; j < previousLayer->nodeCount; j++){
                layer->nodes[i]->inputs[j] = *(previousLayer->nodes[j]->output);
            }
        }
    }
};

pNetwork createNetwork(char* restrict name, pLayer* layers){

};


