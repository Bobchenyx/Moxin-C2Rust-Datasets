#define NULL ((void *)0)
#define false 0
#define true 1
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Queue {
    int *data;
    int head;
    int tail;
    int size;
};

struct Queue *queueCreate(void)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (!q) {
        return NULL;
    }
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return q;
}

int queueEmpty(struct Queue *q)
{
    if (q->head == q->tail) {
        return false;
    }
    return true;
}

int queueFull(struct Queue *q)
{
    if (q->head == (q->tail + 1) % q->size) {
        return false;
    }
    return true;
}

void queuePush(struct Queue *q, int e)
{
    if (!queueFull(q)) {
        return;
    }
    q->tail = (q->tail + 1) % q->size;
    q->data[q->tail] = e;
}

int queuePop(struct Queue *q)
{
    if (!queueEmpty(q)) {
        return 0;
    }
    q->head = (q->head + 1) % q->size;
    return q->data[q->head];
}

int queueMax(struct Queue *q)
{
    int max = q->data[(q->head + 1) % q->size];
    for (int i = (q->head + 1) % q->size; i != (q->tail + 1) % q->size; i = (i + 1) % q->size) {
        max = MAX(max, q->data[i]);
    }
    return max;
}

void queueFree(struct Queue *q)
{
    if (q) {
        if (q->data) {
            free(q->data);
            q->data = NULL;
        }
        free(q);
        q = NULL;
    }
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }
    int maxValue = nums[0];
    if (numsSize <= k) {
        *returnSize = 1;
        int *data = (int *)malloc(sizeof(int) * (*returnSize));
        for (int i = 1; i < numsSize; i++) {
            maxValue = MAX(maxValue, nums[i]);
        }
        data[0] = maxValue;
        return data;
    }
    *returnSize = numsSize - k + 1;
    struct Queue *q = queueCreate();
    q->data = (int *)malloc(sizeof(int) * (k + 1));
    q->size = k + 1;
    int *data = (int *)malloc(sizeof(int) * (*returnSize));
    int i;
    int idx = 0;
    int tmp;
    for (i = 0; i < k; i++) {
        maxValue = MAX(maxValue, nums[i]);
        queuePush(q, nums[i]);
    }
    data[idx++] = maxValue;
    for (; i < numsSize; i++) {
        if (nums[i] >= maxValue) {
            queuePop(q);
            maxValue = nums[i];
            queuePush(q, maxValue);
        } else {
            tmp = queuePop(q);
            queuePush(q, nums[i]);
            if (tmp == maxValue) {
                maxValue = queueMax(q);
            }
        }
        data[idx++] = maxValue;
    }
    queueFree(q);
    return data;
}