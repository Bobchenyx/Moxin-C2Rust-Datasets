/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 10000

typedef struct queue{
    int *datas;
    int capacity;
    int size;
    int front;
    int rear;
}Que;

Que* createQue(int maxsize){
    Que* q = malloc(sizeof(Que));
    q->datas = malloc(maxsize * sizeof(int));
    q->capacity = maxsize;
    q->size = 0;
    q->front = 0;
    q->rear = maxsize - 1;
    
    return q;
}

void enqueue (Que * queue, int val) {
    if (queue->size < queue->capacity) {
         queue->datas[queue->front] = val;
        if (queue->front == queue->capacity)
            queue->front = 0;
        else
            queue->front++;
        queue->size++;
    }
}

int dequeue(Que *queue){
    if (queue->size > 0) {
        if (queue->front == 0)
            queue->front = queue->capacity - 1;
        else
            queue->front--;
        queue->size--;
        return queue->datas[queue->front];
    }
    return -1;
}

int getHead(Que *queue){
    if (queue->size == 0)
        return -1;

    if(queue->front == 0)
        return queue->datas[queue->capacity - 1];
    else
        return queue->datas[queue->front - 1];
}

void enqueueTail(Que *queue, int val){
    if (queue->size < queue->capacity) {
        queue->datas[queue->rear] = val;
        if (queue->rear == 0)
            queue->rear = queue->capacity;
        else
            queue->rear--;
        queue->size++;  
    }
}

int dequeueTail(Que* queue){
    if (queue->size > 0) {
        if (queue->rear == queue->capacity)
            queue->rear = 0;
        else
            queue->rear++;
        queue->size--;
        return queue->datas[queue->rear];
    }
    return -1;
}

int getHeadTail(Que* queue){
    if (queue->size == 0)
        return -1;
    if (queue->rear == queue->capacity)
        return queue->datas[0];
    else
        return queue->datas[queue->rear + 1];
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *res = malloc((numsSize - k + 1) * sizeof(int));
    int i,j = 0;

#if 1
    Que* queue = createQue(numsSize);
    for (i = 0; i < numsSize; i++) {
        while (queue->size && nums[getHeadTail(queue)] < nums[i])
            dequeueTail(queue);

        enqueueTail(queue, i);

        if (getHead(queue) < i - k + 1)
            dequeue(queue);

        if (i >= k - 1)
            res[j++] = nums[getHead(queue)];        
    }
    *returnSize = j;
#else
    int max;    
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    for (i = 0; i <= numsSize - k; i++) {
        max = nums[i];
        for (j = i + 1; j < i + k; j++)
            max = (max > nums[j] ? max : nums[j]);
        res[i] = max;
    }

    *returnSize = i;
#endif
    return res;
}