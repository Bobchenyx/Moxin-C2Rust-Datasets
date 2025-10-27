int longestValidParentheses(char * s){//**以题目给的s为栈，故不用额外空间**
    int len=strlen(s);
    if(len<=1)
        return 0;

    int t=0;//****
    int tail=0;//**栈顶指针，保存栈内第一个‘（’的下标**
    int top=-1;//*栈顶指针，实际上保存‘（’的个数**
    int max=0;
    int m=0;
    
    while(t<len&&tail-m<len-max)**顺序遍历**
    {
        if(s[t]=='(')//**入栈**
        {
            top++;
            if(top==0)
            {
                tail=t;
            }
        }
        else if(s[t]==')')
        {
            if(top>=0)//**出栈**
            {
                top--;
                m+=2;
                if(top<0&&m>max)
                    max=m;  
            }
            else//**清空栈**
            {
                top=-1;
                m=0;
            }
        }
        t++;
    }
    if(top!=-1)
    {
        t=len-1;
        len=tail;
        tail=t;
        top=-1;
        m=0;
        
       while(t>=len&&tail+m>len+max)**逆序遍历**
        {
            if(s[t]==')')//**入栈**
            {
                top++;
                if(top==0)
                {
                    tail=t;
                }
            }
            else if(s[t]=='(')
            {
                if(top>=0)//**出栈**
                {
                    top--;
                    m+=2;
                    if(top<0&&m>max)
                        max=m;  
                }
                else//**清空栈**
                {
                    top=-1;
                    m=0;
                }
            }
        t--;
        }
    }
    
    return max;
}