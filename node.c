//
// Created by sdutton on 14.02.23.
//

#include <stdlib.h>
#include "string.h"
#include "node.h"
#include "malloc.h"
#include "stack.h"
#include "math.h"

pStack stack;

float* randomWeights(int count){
    float* results = malloc( sizeof(float)  * count);
    push(stack,results);
    for(int i=0;i < count; i++){
        results[i] = (float) rand() / RAND_MAX;
    }
    return results;
}

pNeuron createNeuron(int quantity, pNeuronLayer previousLayer){
    pNeuron result = malloc(sizeof (struct neuronDef) * quantity);
    push(stack,result);
    for(int i=0; i<quantity;i++) {
        result->bias = 0.5;
        result->learningRate = 0.5;
        result->value = 0.5;
        if (previousLayer) {
            result->weights = randomWeights(previousLayer->quantity);
            result->inputs = previousLayer->neurons;
        } else{
            result->weights = 0;
            result->inputs = 0;
        }
    }
    return result;
}

pNeuronLayer createNeuronLayer(int neuronQuantity, enum layerTypeEnum layerType, pNeuronLayer previousLayer){
    pNeuronLayer result = malloc(sizeof (struct neuronLayerDef));
    push(stack,result);
    result->neurons = createNeuron(neuronQuantity, previousLayer);
    result->quantity = neuronQuantity;
    result->layerType = layerType;
    if(previousLayer){
        result->prevLayer =previousLayer;
        result->prevLayer->nextLayer = result;
    }
    return result;
}

pNetwork buildNetwork(int layerCount, int* layersNodeCount) {
    stack = initStack();
    pNetwork net = malloc(sizeof (struct networkDef));
    push(stack,net);
    pNeuronLayer previous;
    previous = createNeuronLayer(layersNodeCount[0], input, NULL);
    for (int i = 1; i < layerCount - 1; i++)
    {
        previous = createNeuronLayer(layersNodeCount[i], hidden, previous);
    }
    net->layers = createNeuronLayer(layersNodeCount[layerCount - 1], output, previous);
    net->layerCount = layerCount;
    return net;
}


void freeNetwork(pNetwork net){
    while(1){
        free(pop(stack));
        if(stack->top == 0)
            break;
    }
    free(stack);
}


