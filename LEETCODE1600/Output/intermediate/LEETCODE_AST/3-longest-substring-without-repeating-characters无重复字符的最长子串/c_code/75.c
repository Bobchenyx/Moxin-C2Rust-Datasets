#define ERROR -1
#define OK 0

typedef struct QueueNode {
    char data;
    struct QueueNode* next;
}QueueNode;

typedef struct QueueList {
    QueueNode* head;
    QueueNode* tail;
    int length;
} QueueList;

int QueueEnter(QueueList* Q, char ch);
void InitQueueList(QueueList* Q);
int QueueItemIndex(QueueList Q, char ch);
int QueueDelet(QueueList* Q)

int lengthOfLongestSubstring(char* s) {
    if (s == NULL)return 0;

    int maxlength = 0;
    int i = 0;
    QueueList Q;
    InitQueueList(&Q);
    while (s[i] != '\0') {
        int index = QueueItemIndex(Q, s[i]);
        if (index != -1) {
            for (int i = 0; i < index; i++)
                QueueDelet(&Q);
        }
        QueueEnter(&Q, s[i]);
        if (Q.length > maxlength) maxlength = Q.length;
        i++;
    }
    return maxlength;
}

void InitQueueList(QueueList* Q) {//有头结点
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->next = NULL;
    Q->head = node;
    Q->tail = Q->head;
    Q->length = 0;
}

int QueueItemIndex(QueueList Q, char ch) {
    QueueNode* cur = Q.head->next;
    for (int i = 1; i <= Q.length; i++) {
        if (cur->data == ch)
            return i;
        cur = cur->next;
    }
    return -1;
}

int QueueEnter(QueueList* Q, char ch) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = ch;
    node->next = NULL;
    Q->tail->next = node;
    Q->tail = node;
    Q->length++;
    return OK;
}

int QueueDelet(QueueList* Q) {
    if (Q->head == Q->tail) return ERROR;
    QueueNode* temp = Q->head->next;
    Q->head->next = Q->head->next->next;
    Q->length--;
    if (Q->head->next == NULL) Q->tail = Q->head;
    free(temp);
    return OK;
}