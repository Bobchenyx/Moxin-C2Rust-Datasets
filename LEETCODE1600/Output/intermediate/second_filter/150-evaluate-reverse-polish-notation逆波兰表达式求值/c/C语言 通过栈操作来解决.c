#define STACK_INIT_SIZE 100
#define INCERASIZE 100

typedef struct {
    int * top;
    int * base;
    int stackSize; // 栈的最大容量
} sqStack;

// 初始化栈操作
void InitStack(sqStack * s)
{
    s->base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

// 压栈操作
void PushStack(sqStack * s,int e)
{
    // 判断栈是否满了，满了需要重新分配内存
    if(s->top-s->base==s->stackSize)
    {
        s->base = (int *)realloc(s->base,(s->stackSize+INCERASIZE)*sizeof(int));
        s->top=s->base+s->stackSize;
        s->stackSize=s->stackSize+INCERASIZE;
    }
    *(s->top)=e;
    s->top++;
}

// 出栈操作
int Pop(sqStack * s)
{
    if(s->top==s->base)
        return -1;
    s->top--;
    int x = *(s->top);
    return x;
}


int evalRPN(char ** tokens, int tokensSize)
{
    sqStack s;
    InitStack(&s); // 初始化栈
    int i,x,y;
    for(i=0;i<tokensSize;i++)
    {
        // 如果是符号，取出两个数并计算结果
        if(!strcmp(tokens[i],"+"))
        {
            x=Pop(&s),y=Pop(&s);
            PushStack(&s,x+y);
        }
        else if(!strcmp(tokens[i],"-"))
        {
            x=Pop(&s),y=Pop(&s);
            PushStack(&s,y-x);
        }
        else if(!strcmp(tokens[i],"*"))
        {
            x=Pop(&s),y=Pop(&s);
            PushStack(&s,x*y);
        }
        else if(!strcmp(tokens[i],"/"))
        {
            x=Pop(&s),y=Pop(&s);
            PushStack(&s,y/x);
        }
        else
        {
            // 如果是数字就压栈
            PushStack(&s,atoi(tokens[i]));
        }
    }
    return Pop(&s); // 返回最后在栈中的数字
}