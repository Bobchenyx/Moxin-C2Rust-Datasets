struct Node{
    struct Node *last;
    int val; 
    int min;  
};

typedef struct {
    struct Node *current_node;
} MinStack;


/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    obj->current_node = NULL;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    int min;
    node->val = x;
    if(!(obj->current_node))
    {
        node->last = NULL;
        node->min = x;
    }
    else
    {
        node->last = obj->current_node;
        node->min = (obj->current_node->min < x) ? obj->current_node->min : x;
    }
    obj->current_node =node;
}

void minStackPop(MinStack* obj) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node = obj->current_node;
    obj->current_node = obj->current_node->last;
    free(node);

}

int minStackTop(MinStack* obj) {
    return obj->current_node->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->current_node->min;
}

void minStackFree(MinStack* obj) {
    struct Node* node;
    while(obj->current_node->last != NULL)
    {
        node = obj->current_node;
        obj->current_node = obj->current_node->last;
         free(node);
    }
    free(obj->current_node);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/