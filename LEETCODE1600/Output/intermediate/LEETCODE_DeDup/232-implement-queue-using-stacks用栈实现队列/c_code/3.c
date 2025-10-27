typedef struct myStack {
    int val;
    struct myStack *next;
} MyStack;

typedef struct {
    MyStack *s1;
    int cnt;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *Q = (MyQueue *)malloc(sizeof(MyQueue));
    memset(Q, 0, sizeof(MyQueue));
    return Q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    MyStack *n = (MyStack *)malloc(sizeof(MyStack));
    MyStack *q = NULL, *t = NULL;
    n->val = x;
    n->next = NULL;
/* 从栈1出栈并往栈2（q）入栈 */
    while (obj->s1) {
        t = obj->s1;
        obj->s1 = obj->s1->next;
        t->next = q;
        q = t;
    }
/* 栈1push */
    obj->s1 = n;
/* 从栈2出栈并往栈1入栈 */
    while (q) {
        t = q;
        q = q->next;
        t->next = obj->s1;
        obj->s1 = t;
    }
    obj->cnt++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int res;
    MyStack *p = obj->s1;
    obj->s1 = p->next;
    obj->cnt--;
    res = p->val;
    free(p);
    return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->s1->val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return !obj->cnt;
}

void myQueueFree(MyQueue* obj) {
    MyStack *p = obj->s1, *t;
    while (p) {
        t = p;
        p = p->next;
        free(t);
    }
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/