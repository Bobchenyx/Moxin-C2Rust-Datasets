typedef struct myQueue{
    int* queue;
    int head;
    int rear;
    int size;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue * obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    obj->queue=malloc(k*sizeof(int));
    obj->head=0;
    obj->rear=0;
    obj->size=k;
    while(k){
        (obj->queue)[--k]=-1;
    }
    return obj;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return ((obj->head==obj->rear)&&((obj->queue)[obj->head]==-1));

}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return(obj->head==0&&obj->rear==obj->size-1||obj->head==obj->rear+1);
  //这个和大话数据结构上的是不太一样的
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)){
        return 0;
    }
    else if(myCircularQueueIsEmpty(obj)){
        (obj->queue)[obj->head]=value;
        return 1;
    }
    obj->rear++;
    if(obj->rear==obj->size){
        obj->rear=obj->rear-obj->size;
    }else if(obj->rear==obj->head){
            return 0;
    }
    (obj->queue)[obj->rear]=value;
    return 1;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return 0;
    }
    (obj->queue)[obj->head]=-1;
    if(obj->head!=obj->rear){
        obj->head++;
    }
    return 1;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    return (obj->queue)[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    return (obj->queue)[obj->rear];
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/