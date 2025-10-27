int maximum69Number (int num){
    int stack[4];
    int top=-1;

    while(num!=0)
    {
        stack[++top]=num%10;
        num/=10;
    }
    
    int first6=1;
    while(top!=-1)
    {
        num*=10;
        if(stack[top]==6&&first6)
        {
            num+=9;
            top--;
            first6=0;
        }
        else
            num+=stack[top--];
    }    

    return num;
}