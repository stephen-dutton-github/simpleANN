

typedef struct nodeDef{
    float** inputs;
    float** weights;

    float (*regression) (float);
    float (*sigmoid) (float);
    float (*relu) (float);
} node, *pNode;
