#define MAX_NUM 20001

typedef struct {
    int index;
    int stackValues[MAX_NUM];
    int minStackValues[MAX_NUM];
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* res = (MinStack*)malloc(sizeof(MinStack));

    if (res == NULL) {
        return res;
    }
    res->index = 0;

    return res;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->index == 0) {
        obj->stackValues[obj->index] = x;
        obj->minStackValues[obj->index] = x;
    } else {
        obj->stackValues[obj->index] = x;
        obj->minStackValues[obj->index] =
            obj->minStackValues[obj->index - 1] > x ? x : obj->minStackValues[obj->index - 1];
    }

    obj->index++;
}

void minStackPop(MinStack* obj) {
    obj->index--;

}

int minStackTop(MinStack* obj) {
    return obj->stackValues[obj->index - 1];
}

int minStackMin(MinStack* obj) {
    return obj->minStackValues[obj->index - 1];
}

void minStackFree(MinStack* obj) {
    free(obj);
}