


#ifndef SIMPLEANN_NODE_H
#define SIMPLEANN_NODE_H

#define INPUT_NODES 480000
#define HIDDEN_NODES 100
#define OUTPUT_NODES 5

#define LEARNING_RATE 0.5f;

enum layerTypeEnum {input,hidden, output};

typedef struct networkNodesDescriptor{
    int layers;
    int index;
    int* layerSpec
} netNodes, *pNetNodes;

typedef struct denseNodeDef{
    float value;
    float bias;
    float learningRate;
    struct denseNodeDef* inputs;
    float* weights;
} denseNode, *pDenseNode;

typedef struct nodeDef{
    float output;
    float bias;
    float* learningRate;
    float* inputs;
    float* weights;

} node, *pNode;

typedef struct layerDef
{
    unsigned int layerNumber;
    enum layerTypeEnum layerType;
    pNode nodes;
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

extern char* restrict nodeErrorMessage;
pNode       createNodes(unsigned int quantity, unsigned int numberOfInputs, enum layerTypeEnum type);
pLayer      createLayer(unsigned int nodeCount, pLayer previousLayer, enum layerTypeEnum type);
pNetwork    createNetwork(char* restrict name, pLayer* layers);
int         createDenseNetwork(short layers, int inputLayerNodes, int hiddenLayerNodes, int outputLayerNodes, pNetwork result);


float* randomWeights(int count);
void freeNode(pNode);
#endif

