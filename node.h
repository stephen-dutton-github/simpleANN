


#ifndef SIMPLEANN_NODE_H
#define SIMPLEANN_NODE_H

#define LEARNING_RATE 0.5f;


enum layerType {input,hidden, output};

typedef struct nodeDef{
    float* learningRate;
    float* inputs;
    float* weights;
    float (*regression) (float);
    float* output;
} node, *pNode;

typedef struct layerDef
{
    unsigned int layerNumber;
    enum layerType _layerType;
    pNode* nodes;
    unsigned int nodeCount;
} layer, *pLayer;



typedef struct networkDef{
    char* restrict name;
    enum layerType lType;
    pLayer* allLayers;
    pLayer input;
    pLayer output;
} network, *pNetwork;

pNode createNode(unsigned int quantity, enum layerType type);

pLayer createLayer(unsigned int nodeCount, enum  layerType _layerType, pLayer proceedingLayer);
pNetwork createNetwork(char* restrict name, pLayer* layers);

float* randomWeights(int count);
void freeNode(pNode);
#endif

