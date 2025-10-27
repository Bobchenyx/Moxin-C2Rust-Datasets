typedef struct Node {
    int element;
    struct Node *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->element = 0;
    head->next = NULL;

    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *p = obj->next;
    int j = 0;

    while ((p != NULL) && (j < index)) {
        p = p->next;
        j++;
    }

    if ((p == NULL) || (index < 0)) {
        return -1;
    } else {
        return p->element;
    }
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *p = obj;
    MyLinkedList *s = (MyLinkedList *)malloc(sizeof(MyLinkedList));

    s->element = val;
    s->next = p->next;
    p->next = s;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *p = obj;
    MyLinkedList *s = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    s->element = val;
    s->next = NULL;// 尾结点指向空

    // 找到尾结点
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = s;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *p = obj->next;
    MyLinkedList *q = obj;
    int j = 0;
    
    //从第0个节点开始找到第index个结点，并用p指向第index个节点，q指向第index个的前驱结点
    while (p != NULL && j < index) {
        j++; 
        p = p->next;
        q = q->next;
    }

    if (p != NULL || j >= index) {
        p = (MyLinkedList *)malloc(sizeof(MyLinkedList));
        p->element = val;
        p->next = q->next; // q为前驱节点
        q->next = p;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int j = 0;
    MyLinkedList *p = obj->next;
    MyLinkedList *q = obj;    
    
    // 从第0个节点开始找到第index个结点，并用p指向第index个节点，q指向第index个的前驱结点
    while (p != NULL && j < index) {
        j++;  
        p = p->next;
        q = q->next;
    }   

    // 第index个结点存在，则删除,index<0即index为无效值，则不删除
    if (p != NULL && index >= 0) {
        p = q->next;
        q->next=p->next;
        free(p); // 节点删除后，对应内存空间应释放，避免内存泄漏
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* p = obj->next;
    MyLinkedList* q;

    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    obj->next = NULL;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/