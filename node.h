
typedef float (*regression) (float);
typedef float (*sigmoid) (float);
typedef float (*relu) (float);
typedef float (*softmax) (float);
typedef float* (*chain)(float*);

typedef struct nodeDef{
    float** inputs;
    float** weights;
    chain _chain;
    relu output;
} node, *pNode;

