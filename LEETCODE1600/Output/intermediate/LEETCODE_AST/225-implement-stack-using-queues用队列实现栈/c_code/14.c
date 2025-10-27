#define MAX_NUM_SIZE 10000
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int head;
    int tail;
    int size;
    int data[MAX_NUM_SIZE];
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* res = (MyStack*)malloc(sizeof(MyStack));
    res->head = 0;
    res->tail = 0;
    res->size = 0;
    return res;
}

bool myStackFull(MyStack* obj) {
    return obj->size == MAX_NUM_SIZE;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {

    if (myStackFull(obj)) {
        return;
    }
    obj->tail = (obj->tail + 1) % MAX_NUM_SIZE;
    obj->data[obj->tail] = x;
    obj->size++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (myStackEmpty(obj)) {
        return 0;
    }
    int res = obj->data[obj->tail];
    obj->tail = (obj->tail - 1 + MAX_NUM_SIZE) % MAX_NUM_SIZE;
    obj->size = MAX(obj->size - 1, 0);
    return res;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (myStackEmpty(obj)) {
        return 0;
    }
    return obj->data[obj->tail];
}


void myStackFree(MyStack* obj) {
    if (obj != NULL) {
        free(obj);
    }
    obj = NULL;
}