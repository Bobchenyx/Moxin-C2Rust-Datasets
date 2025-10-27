#define MAX_N 110001

typedef struct {
    int front1, rear1;
    int queue1[MAX_N];
    int front2, rear2;
    int queue2[MAX_N];//单调不增队列，队头是最大值
} MaxQueue;

MaxQueue* maxQueueCreate() {
    return (MaxQueue *)calloc(1, sizeof(MaxQueue));
}

int maxQueueMax_value(MaxQueue* obj) {
    if (obj->front2 != obj->rear2) {
        return obj->queue2[obj->front2];
    }
    return -1;
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    obj->queue1[obj->rear1++] = value;

    while (obj->rear2 != obj->front2 && obj->queue2[obj->rear2 - 1] < value) {
        obj->rear2--;
    }
    obj->queue2[obj->rear2++] = value;
}

int maxQueuePop_front(MaxQueue* obj) {
    int val;
    if (obj->front1 == obj->rear1) {
        return -1;
    }
    val = obj->queue1[obj->front1++];
    if (val == obj->queue2[obj->front2]) {
        obj->front2++;
    }

    return val;
}

void maxQueueFree(MaxQueue* obj) {
    free(obj);
}