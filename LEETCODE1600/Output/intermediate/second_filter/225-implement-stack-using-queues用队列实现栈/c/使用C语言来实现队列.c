typedef struct {
    int data[10000];
    int top;
    int rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* obj;
    obj=(MyStack*)malloc(sizeof(MyStack));
    obj->top=0;
    obj->rear=-1;
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->rear++;
    obj->data[obj->rear]=x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
  obj->rear--;
  return obj->data[obj->rear+1];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
  return obj->data[obj->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
  if(obj->top>obj->rear)
      return true;
    return false;
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