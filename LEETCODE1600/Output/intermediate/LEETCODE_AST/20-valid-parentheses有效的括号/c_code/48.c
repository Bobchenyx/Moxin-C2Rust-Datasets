typedef char Datatype;

typedef struct stack{
    int MAXNUM;
    int top;
    Datatype *s;
}seqstack;
//创建空栈
seqstack *createEmptyStack_seq(int m)
{
    seqstack *mystack=(seqstack*)malloc(sizeof(seqstack));
    if(mystack==NULL)
    {
        printf("创建失败！");
        return NULL;
    }
    mystack->MAXNUM=m;
    mystack->top=-1;
    mystack->s=(Datatype*)malloc(sizeof(Datatype)*m);
    return mystack;
}
//入栈
void push_sepstack(seqstack *mystack,Datatype x)
{
    if(mystack->top>=mystack->MAXNUM-1)
        printf("overflow!\n");
    else
    {
        mystack->top=mystack->top+1;
        mystack->s[mystack->top]=x;
    }
}
//出栈
void pop_seq(seqstack *mystack)
{
    if(mystack->top==-1)
        printf("underflow!\n");
    else
        mystack->top=mystack->top-1;
}

//取栈顶元素
Datatype get_top_sep(seqstack *mystack)
{
    if(mystack->top==-1)
        printf("It is empty!\n");
    else
        return (mystack->s[mystack->top]);
    
    return 0;
}


bool isValid(char *s){
    int i=0;
    seqstack *mystack=createEmptyStack_seq(10000);
    while(s[i]!='\0')
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            push_sepstack(mystack,s[i]);
        }
        else
        {
            char tmp=get_top_sep(mystack);
            if(tmp==s[i]-1||tmp==s[i]-2)
                pop_seq(mystack);
            else
                return false;
        }
        i++;
    }
    if(mystack->top==-1)
        return true;
    else
        return false;

}