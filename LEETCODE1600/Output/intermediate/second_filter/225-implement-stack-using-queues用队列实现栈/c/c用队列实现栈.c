typedef struct a{
    int queey[100];
    int head,tail; 
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack * abc = (MyStack * )malloc(sizeof(MyStack));
    abc->head = 0;
    abc->tail = 0;
    return abc;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->queey[obj->tail++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int top = obj->queey[obj->tail-1];
    for(int i=0;i<obj->tail-obj->head-1;i++){
        obj->queey[obj->tail++] = obj->queey[obj->head++];
    }
    obj->head++;
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queey[obj->tail-1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->head == obj->tail;
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