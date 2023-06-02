


#ifndef SIMPLEANN_NODE_H
#define SIMPLEANN_NODE_H

#define INPUT_NODES 480000
#define HIDDEN_NODES 100
#define OUTPUT_NODES 5

#define LEARNING_RATE 0.5f;



enum layerTypeEnum {input,hidden, output};

typedef struct neuronDef{
    float value;
    float bias;
    float learningRate;
    struct neuronDef* inputs;
    float* weights;
} neuron, *pNeuron;

typedef struct neuronLayerDef{
    int quantity;
    pNeuron neurons;
    enum layerTypeEnum layerType;
    struct neuronLayerDef* nextLayer;
    struct neuronLayerDef* prevLayer;
} neuronLayer, *pNeuronLayer;


typedef struct networkDef{
    int layerCount;
    pNeuronLayer layers;
} network, *pNetwork;

extern char* restrict nodeErrorMessage;
void initStack();
pNeuron createNeuron(int quantity, pNeuronLayer previousLayer);
pNeuronLayer createNeuronLayer(int neuronQuantity, enum layerTypeEnum layerType, pNeuronLayer previousLayer);
pNetwork buildNetwork(int layerCount, int* LayerNeuronCount);
void freeNetwork(pNetwork network);


#endif