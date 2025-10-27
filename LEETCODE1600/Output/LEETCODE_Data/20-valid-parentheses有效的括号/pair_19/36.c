bool isValid(char * s){
    int len = strlen(s);
   //空串返回为真
    if (0 == len)
    {
        return true;
    }
    //字符为奇数个，肯定假
    else if (0 != len % 2)
    {
        return false;
    }
    else
    {
        int top = 0;
        //从数组下标为1开始记，如果栈内没有数，则下表应该为0，所以最长入栈个数为len 加上第一个预留出来，则为n+1
        char stack[len + 1] ;
        stack[0] = '\0';
        for (int i = 0; i < len ; i++)
        {
            //如果为左括号，进栈
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
            {
                top ++;
                stack[top] = s[i];
            }
            // （）相差1 ，[]和{}}相差2
            else if ((s[i] == stack[top] + 1) || (s[i] == stack[top] + 2))
            {
                top --;
            }
        }
        return  (top != 0)?false:true;
    } 

}