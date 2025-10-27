#define MAX_NUM 10001

typedef struct {
    int *data;
    int front;
    int tail;
    int max;
    int num;
} RecentCounter;

RecentCounter counter;

bool isFull(RecentCounter* obj)
{
    return (obj->num == obj->max) ? true : false;
}

bool isEmpty(RecentCounter* obj)
{
    return (obj->num == 0) ? true : false;
}

int getTop(RecentCounter* obj)
{
    if (isEmpty(obj)) {
        return -1;
    }
    return (obj->data[obj->front]);
}

int getNum(RecentCounter* obj)
{
    return obj->num;
}

void insert(RecentCounter* obj, int value)
{
    if (isFull(obj)) {
        return;
    }

    obj->tail = (obj->tail + 1) % MAX_NUM;
    obj->data[obj->tail] = value;
    obj->num++;

    if (obj->num == 1) {
        obj->front = obj->tail;
    }
    return;
}

int pop(RecentCounter* obj) 
{
    int value;
    if (isEmpty(obj)) {
        return -1;
    }

    value = obj->data[obj->front];
    obj->front = (obj->front + 1) % MAX_NUM;
    obj->num--;
    if (obj->num == 0) {
        obj->front = -1;
        obj->tail = -1;
    }
    return value;
}

RecentCounter* recentCounterCreate() {
    counter.data = (int *)malloc(sizeof(int) * MAX_NUM);
    if (counter.data == NULL) {
        return NULL;
    }

    memset(counter.data, 0, sizeof(int) * MAX_NUM);
    counter.front = -1;
    counter.tail = -1;
    counter.num = 0;
    counter.max = MAX_NUM;
    return &counter;
}

int recentCounterPing(RecentCounter* obj, int t) {
    insert(obj, t);
    while (!isEmpty(obj) && (getTop(obj) < (t - 3000))) {
        pop(obj);
    }
    return getNum(obj);
}

void recentCounterFree(RecentCounter* obj) {
    if (obj->data) {
        free(obj->data);
        obj->data = NULL;
    }
    return;
}