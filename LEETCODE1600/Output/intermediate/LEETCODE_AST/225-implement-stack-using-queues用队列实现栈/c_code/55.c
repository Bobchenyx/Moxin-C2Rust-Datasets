#define MAXSIZE 1000

typedef struct {
    int nums[MAXSIZE];
    int front, rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *m = (MyStack*)calloc(1, sizeof(MyStack));
    re->front = 0;
    re->rear = -1;
    return m;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->nums[++(obj->rear)] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int x = obj->nums[(obj->rear)--];
    return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->nums[obj->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->rear == -1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}