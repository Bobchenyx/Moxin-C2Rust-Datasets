#define STACK_MAX 200000

enum ElmType {  //元素类型
    VALUE,
    SYM
};

typedef struct tagElm  //元素
{
    int val;
    char type;
    struct tagElm *pre;
    struct tagElm *next;    
}Element;

typedef struct tagStack {
    int index;
    Element *data;   //当前元素指针
}Stack;

int IsFull(Stack *st) 
{
    return (st->index == STACK_MAX) ? 1 : 0;
}

int IsEmpty(Stack *st)
{
    return (st->index == 0) ? 1 : 0;
}

//初始化
void IniStack(Stack *st)
{
    st->index = 0;
    st->data = NULL;
}

//入栈
int Push(Stack *st, int c, char type)
{
    if (IsFull(st)) {
        return 0;
    }
    Element * el = (Element *)malloc(sizeof(Element));
    el->type = type;
    el->val = c;
    el->next = NULL;
    if(st->index == 0) {
        el->pre = NULL;
        st->data = el;
    } else {
        st->data->next = el;
        el->pre = st->data;
        st->data = el;
    }
    st->index++;
    return 1;
}

//出栈
int Pop(Stack *st, int *c, char *et)
{
    if(IsEmpty(st)) {
        return 0;
    }
    *c = st->data->val;
    *et = st->data->type;
    Element *tmp = st->data;
    if(st->index > 1) {
        st->data = st->data->pre;
        st->data->next = NULL;
    } else {
        st->data = NULL;
    }    
    free(tmp);
    st->index--;
    return 1;
}

void FreeStack(Stack *st)
{
    int val;
    char type;
    while (!IsEmpty(st))
    {
        Pop(st, &val, &type);
    }
}

int CalcStack(Stack *st)
{
    int res = 0;
    int tmp = 0;
    char et = VALUE;
    char sym = '+';
    while (Pop(st, &tmp, &et) == 1) {
        if(et == SYM && (tmp == '+' || tmp == '-')) {
            sym = (char) tmp;
        } else {
            if(sym == '+') {
                res += tmp;
            } else {
                res -= tmp;
            }
        }
    }
    return res;
}

int calculate(char * s){
    int i, intLen = 0, elTmp;
    int len = strlen(s);
    char et = VALUE;
    char intTmp[30] = {0};
    Stack * st = (Stack *)malloc(sizeof(Stack));
    Stack * stTmp = (Stack *)malloc(sizeof(Stack));
    IniStack(st);
    IniStack(stTmp);  
    for ( i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i]=='-') {  
            Push(st, s[i], SYM);
        } else if (s[i] == ' ') {  //如果是空格，则跳过
            continue;
        } else if (s[i] == ')') {  //如果是)，则计算前面的一个小的运算结构，再回压堆栈
            while (Pop(st, &elTmp, &et)) {
                if (elTmp == '(' && et == SYM) {
                    break;
                }
                Push(stTmp, elTmp, et);
            }
            elTmp = CalcStack(stTmp);           
            Push(st, elTmp, VALUE);
        } else {    //处理数值
            intTmp[intLen++] = s[i];
            if((i+1 == len) || (s[i+1] < '0' || s[i+1] > '9')) {
                Push(st, atoi(intTmp), VALUE);
                intLen = 0;
                memset(intTmp, 0 ,10);
            }
        }        
    }
    while (Pop(st, &elTmp, &et)) {  //计算最后的表达式
        Push(stTmp, elTmp, et);
    }    
    elTmp = CalcStack(stTmp);
    FreeStack(st);
    free(st);
    FreeStack(stTmp);
    free(stTmp);
    return elTmp;
}