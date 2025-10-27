struct Node {
    char c;
    struct Node * next;
};

void push(struct Node ** head_ptr, char c) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->c = c;
    node->next = *head_ptr;
    *head_ptr = node;
}

char pop(struct Node ** head_ptr) {
    if (*head_ptr == NULL)
        return 0;

    struct Node * tmp = *head_ptr;
    *head_ptr = tmp->next;

    char c = tmp->c;
    free(tmp);
    return c;
}

void stackFree(struct Node * head) {
    struct Node * tmp = head;
    while (head != NULL) {
        head = head->next;
        free(tmp);
        tmp = head;
    }
}

// 使用栈來處理非常方便
bool isValid(char * s){
    struct Node * head = NULL;
    while (*s != 0) {
        // 此處使用哈希表來處理可以節省三分之一的時間，但空間開銷會增大
        if (head != NULL && (*s == head->c + 1 || *s == head->c + 2))
            // 栈非空並且可以配對時彈出
            pop(&head);
        else
            // 壓入栈
            push(&head, *s);
        ++s;
    }

    if (head == NULL)
        return 1;
    else {
        stackFree(head);
        return 0;
    }
}