typedef struct {
    int data[1024];
    int top;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *s=(MyStack *)malloc(sizeof(MyStack));
    s->top=-1;
    return s;

}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->top++;
    obj->data[obj->top]=x;


}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int res;
    res = obj->data[obj->top];
    obj->top--;
    return res;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int *p;
    p=obj->data[obj->top];
    return p;

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top==-1)
    return 1;
    else
    return 0;

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