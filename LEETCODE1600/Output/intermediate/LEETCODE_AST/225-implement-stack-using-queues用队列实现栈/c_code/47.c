typedef struct {
    int data[1001];
    int top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack=(MyStack*)malloc(sizeof(MyStack));
    stack->top=0;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->data[obj->top++]=x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return obj->data[--obj->top];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->data[obj->top-1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top) return false;
    else return true;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/