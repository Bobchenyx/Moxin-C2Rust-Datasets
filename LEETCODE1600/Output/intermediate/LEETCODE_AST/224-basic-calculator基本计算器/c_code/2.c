int calculate(char * s){

    int length=strlen(s);
    int mark=0;

    //for stack
    char *stack=(char *)malloc(sizeof(char)*(length+2));
    int top=-1;//永远指向栈顶元素，方便比较
    stack[length+1]='\0';
    stack[++top]='*';

    //for target
    int *target=(int *)malloc(sizeof(int)*(length));
    int count=-1;

    int privilege_in[6]={0,0,-1,2,0,2};//栈内优先级：开括号：40，星号：42，加：43，减：45
    int privilege_out[6]={3,0,0,1,0,1};//栈外优先级：开括号：40，闭括号：41，加：43，减：45

    for(mark;mark<length;mark++)
    {
        if(s[mark]==' ')//空字符，无效
        continue;
        else if(s[mark]>='0'&&s[mark]<='9')//数字,直接保存
        {
            if(mark>0&&s[mark-1]>='0'&&s[mark-1]<='9')
            {
                long a=(long)target[count]*10+(long)s[mark]-'0';
                
                target[count]=(int)a;
            }
            else
            target[++count]=s[mark]-'0';
        }
        else//符号
        {

            if(privilege_in[stack[top]-40]<privilege_out[s[mark]-40])//栈顶元素优先级小于栈外元素优先级，入栈
            {
                stack[++top]=s[mark];
            }
            else//栈内开始出栈
           {
            while(privilege_in[stack[top]-40]>=privilege_out[s[mark]-40])
            {

                if(privilege_in[stack[top]-40]>privilege_out[s[mark]-40])//栈顶大于栈外，出栈
                {
                    if(stack[top--]=='+')//栈顶是加号
                        {
                            target[count-1]=target[count-1]+target[count];
                            count--;

                        }
                    else//栈顶是减号
                    {
                        target[count-1]=target[count-1]-target[count];
                        count--;

                    }
                }
                else
                {
                    top--;
                    break;
                }
            }
            if(s[mark]!=')')
            stack[++top]=s[mark];
           }

        }

    }
        while(top>0)//里面还有符号
    {
        if(stack[top--]=='+')//栈顶是加号
                        {
                            target[count-1]=target[count-1]+target[count];
                            count--;
                        }
                    else//栈顶是减号
                    {
                    target[count-1]=target[count-1]-target[count];
                    count--;
                    }
    }
    return target[0];
}