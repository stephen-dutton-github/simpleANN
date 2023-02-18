


#ifndef SIMPLEANN_NODE_H
#define SIMPLEANN_NODE_H


#define INPUT_NODES 480000
#define HIDDEN_NODES 1000
#define OUTPUT_NODES 5

#define LEARNING_RATE 0.5f;

enum layerTypeEnum {input,hidden, output};

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
    enum layerTypeEnum _layerType;
    pNode* nodes;
    unsigned int nodeCount;
} layer, *pLayer;



typedef struct networkDef{
    char* restrict name;
    enum layerTypeEnum lType;
    unsigned int layerCount;
    pLayer* allLayers;
    pLayer input;
    pLayer output;
} network, *pNetwork;

pNode createNode(unsigned int quantity, enum layerTypeEnum type);

pLayer createLayer(unsigned int nodeCount, enum  layerTypeEnum _layerType, pLayer previousLayer);
pNetwork createNetwork(char* restrict name, pLayer* layers);

float* randomWeights(int count);
void freeNode(pNode);
#endif

