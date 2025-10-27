#define MAXSIZE 100
#define INCREASESIZE 100

/* 动态顺序栈结构 */
typedef struct stack {
    int* data;
    int top;
    int stacksize;
}Stack;

/* 入栈，栈满拓展栈空间 */
void Push(Stack* obj, int x) {
    if (obj->top == obj->stacksize - 1) {
        obj->data = (int*)realloc(obj->data, sizeof(int) * (obj->stacksize + INCREASESIZE));
        obj->stacksize += INCREASESIZE;
    }
    obj->data[++obj->top] = x;
}

/* 取栈顶的同时出栈 */
int TopAndPop(Stack* obj) {
    int x = obj->data[obj->top--];
    return x;
}

int evalRPN(char ** tokens, int tokensSize){
    Stack* obj = (Stack*)malloc(sizeof(Stack));
    obj->top = -1;
    obj->stacksize = MAXSIZE;
    obj->data = (int*)malloc(sizeof(int) * MAXSIZE);
    int x, y;
    for (int i = 0; i < tokensSize; i++) {
        //如果是运算符，取两次栈顶，计算，并将结果入栈
        if (!strcmp(tokens[i], "+")) {
            x = TopAndPop(obj); y = TopAndPop(obj);
            Push(obj, y + x);
        }
        else if(!strcmp(tokens[i], "-")) {
            x = TopAndPop(obj); y = TopAndPop(obj);
            Push(obj, y - x);
        }
        else if(!strcmp(tokens[i], "*")) {
            x = TopAndPop(obj); y = TopAndPop(obj);
            Push(obj, y * x);
        }
        else if(!strcmp(tokens[i], "/")) {
            x = TopAndPop(obj); y = TopAndPop(obj);
            Push(obj, y / x);
        }
        //子字符串为操作数，将其化为整型并入栈
        else {
            Push(obj, atoi(tokens[i]));
        }
    }
    return TopAndPop(obj);   //返回最后栈的唯一一个数
}