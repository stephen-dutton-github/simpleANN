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

pNode createNodes(unsigned int quantity, unsigned int numberOfInputs, enum layerTypeEnum type ){

    size_t nodeSize = sizeof (struct nodeDef);
    pNode startNode = malloc(nodeSize * quantity);

    for(unsigned i=0;i < quantity; i++){
        startNode[i].output=0.5;
        startNode[i].bias=0.5;

        switch(type){
            case hidden:
            case output:
                startNode[i].inputs =malloc(numberOfInputs * sizeof(float) );
                startNode[i].weights=randomWeights(numberOfInputs);
            break;
        }
    }
    return startNode;
};

void freeNode(pNode node){
    free(node->weights);
}

pLayer createLayer(unsigned int nodeCount,  pLayer previousLayer, enum layerTypeEnum lt)
{
    int previousLayerCount = 0;
    pLayer layer= malloc(sizeof(struct layerDef));
    layer->nodes = createNodes(nodeCount, previousLayer ? previousLayer->nodeCount : 0, lt);
    layer->nodeCount = nodeCount;
    layer->layerType = lt;
    if(previousLayer){

            for(unsigned i=0;i < nodeCount; i++){
                for(unsigned int j=0; j < previousLayer->nodeCount; j++){
                    node nodeBuffer = previousLayer->nodes[j];
                    layer->nodes[i].inputs[j] = nodeBuffer.output;
            }
        }
    }
};

pNetwork createNetwork(char* restrict name, pLayer* layers){

};

void initDescriptor(struct networkNodesDescriptor* nnd, int layers, int* lspc){
    nnd->layerSpec = malloc(sizeof (int) * layers);
    for(int i=0; i < layers; i++)
        nnd->layerSpec[i] = lspc[i];
    nnd->index=0;
}

void freeDescriptor(struct networkNodesDescriptor* nnd){
    free(nnd->layerSpec);
}


int createDenseNetwork(short layers, int inputLayerNodes, int hiddenLayerNodes, int outputLayerNodes, pDenseNode result)
{
    if(layers > 256){
        nodeErrorMessage = "too many layers";
        return -1;
    }
    pNetNodes nnd = malloc(sizeof (struct networkNodesDescriptor));
    int arry[layers];
    arry[0] = outputLayerNodes;
    for(int i = 0; i <= layers-2; i++){
        arry[0] = hiddenLayerNodes;
    }
    arry[layers-1] = outputLayerNodes;
    initDescriptor(nnd,);
}

int createFixedDenseNetwork(pDenseNode result)
{
    return 0;
}


pDenseNode recurseBuild(pDenseNode parentRootNode,int parentNodesCount, pNetNodes nnd){
    if((nnd->layers- 1) ==  nnd->index){
        return parentRootNode;
    }
    pDenseNode local = malloc(nnd->layerSpec[nnd->index] * sizeof(denseNode) );
    for(int i=0; i < nnd->layerSpec[nnd->layers - nnd->index]; i++){
        for(int j; j<parentNodesCount;j++){
            parentRootNode[i].inputs[j] = local[j];
        }
    }

}




