
#define LEARNING_RATE 0.5f;

enum layerType {input,hidden, output};

typedef struct nodeDef{
    float* learningRate;
    float** inputs;
    float** weights;
    float (*regression) (float);
} node, *pNode;

typedef struct layerDef
{
    int layNumber;
    enum layerType _layerType;
    pNode* nodes;
} layer, *pLayer;

typedef struct networkDef{
    char* restrict name;
    pLayer* allLayers;
    pLayer input;
    pLayer output;
} network, *pNetwork;

pNode createNode();
pLayer createLayer(int count, enum  layerType _layerType, pLayer proceedingLayer);
pNetwork createNetwork(char* restrict name, pLayer* layers);

