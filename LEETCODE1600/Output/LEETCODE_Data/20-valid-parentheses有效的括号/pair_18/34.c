c []
typedef struct StackNode{
    char data;
    struct StackNode *next;
} LinkStack, *stack_ptr;

bool ismatch(char first, char second) {
    if (second - first == 1 || second - first == 2) return true;
    return false;
}

void push(stack_ptr *stack, char bracket) {
    stack_ptr node = (stack_ptr)malloc(sizeof(LinkStack));
    node->data = bracket;
    node->next = *stack;  // 交换头结点
    *stack = node;  // 改变头结点
}

void pop(stack_ptr *stack) {
    if (*stack) {  // 不空
        stack_ptr q = *stack;  // q暂存删除结点
        *stack = (*stack)->next;
        free(q);  // 删除结点
    }else return;
}

void destroy(stack_ptr *stack) {
    stack_ptr tmp;
    while (*stack) {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

bool isValid(char * s){
    /* 1.初始化链表栈 */
    stack_ptr stack = NULL;
    /* 2.准备添加元素 */
    while (*s != '\0') {
        if (stack && ismatch(stack->data, *s)) {
            pop(&stack);  // 传入二级指针
            s++;  // 字符移动
        }else push(&stack, *s++);
    }
    bool res = !stack;
    destroy(&stack);
    return res;
}