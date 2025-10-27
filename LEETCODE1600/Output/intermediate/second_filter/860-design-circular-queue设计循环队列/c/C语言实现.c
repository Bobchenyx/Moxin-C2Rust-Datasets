typedef struct MyCircularQueue
{
    int front, rear;
    int size;
    int data[];
} MyCircularQueue, *MyCircularQueuePtr;

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue) + (k+1) * sizeof(int));
    if(!obj)
        return NULL;
    memset(obj, 0, sizeof(MyCircularQueue) + (k+1) * sizeof(int));
    obj->rear = obj->front = 0;
    obj->size = k + 1;

    return obj;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //判断是否full
    if(myCircularQueueIsFull(obj))
        return false;
    
    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->size;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    //判断是否empty
    if(myCircularQueueIsEmpty(obj))
        return false;

    obj->front = (obj->front + 1) % obj->size;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    //判断是否为空队列
    if(myCircularQueueIsEmpty(obj))
        return -1;

    return obj->data[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    //判断是否为空队列
    if(myCircularQueueIsEmpty(obj))
        return -1;
    
    int index = (obj->rear - 1 + obj->size) % obj->size;
    return obj->data[index];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->rear == obj->front ? true : false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % obj->size == obj->front ? true : false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
    obj = NULL;
}