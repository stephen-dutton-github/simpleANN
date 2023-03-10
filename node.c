//
// Created by sdutton on 14.02.23.
//

#include <stdlib.h>
#include "string.h"
#include "node.h"
#include "malloc.h"

#include "math.h"


float* randomWeights(int count){
    float* results = malloc( sizeof(float)  * count);
    for(int i=0;i < count; i++){
        results[i] = (float) rand() / RAND_MAX;
    }
    return results;
}

pNeuron createNeuron(int quantity, pNeuronLayer previousLayer){
    pNeuron result = malloc(sizeof (struct neuronDef) * quantity);
    for(int i=0; i<quantity;i++) {
        result->bias = 0.5;
        result->learningRate = 0.5;
        result->value = 0.5;
        if (previousLayer) {
            result->weights = randomWeights(previousLayer->quantity);
            result->inputs = previousLayer->neurons;
        }
    }

}

pNeuronLayer createNeuronLayer(int neuronQuantity, enum layerTypeEnum layerType, pNeuronLayer previousLayer){
    pNeuronLayer result = malloc(sizeof (struct neuronLayerDef));
    result->neurons = createNeuron(neuronQuantity, previousLayer);
    result->quantity = neuronQuantity;
    if(previousLayer){
        result->prevLayer =previousLayer;
        result->prevLayer->nextLayer = result;
    }
    return result;
}

pNetwork buildNetwork(int layerCount, int* layersNodeCount) {
    pNeuronLayer previous;
    previous = createNeuronLayer(layersNodeCount[0], input, NULL);
    for (int i = 1; i < layerCount - 1; i++)
    {
        previous = createNeuronLayer(layersNodeCount[i], hidden, previous);
    }
    createNeuronLayer(layersNodeCount[layerCount - 1], output, previous);

}


void freeNetwork(pNetwork network){
    for(int i =0; i < network->layerCount; i++){
        if(network->layers->neurons->weights)
        {
            free(network->layers->neurons->weights);
        }
        if(network->layers->neurons)
        {
            free(network->layers->neurons);
        }
        if(network->layers)
        {
            free(network->layers);
        }

    }
}


