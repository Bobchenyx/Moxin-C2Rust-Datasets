bool isValid(char * s){
char *str;
int  i=0, n;
long int top=0;
n=strlen(s);
str=(char *)malloc(sizeof(char)*(n+1));
// 预留一个判空;
str[0]='a';
while(s[i]!='\0') //退出的条件;
{
       // 左括号进栈;
        if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
        {
               top++;
               str[top]=s[i]; 
        }
        else
        {
                            
                 //判段不退栈的条件;
                  if(s[i]==')'&&(str[top]=='{' || str[top]=='[' ||str[top]=='a' ) )
                  return false;
                  else if(s[i]=='}' &&  (str[top]=='[' || str[top]=='(' || str[top]=='a')  )
                   return false;
                  else  if(s[i]==']' && ( str[top]== '{' || str[top]=='('|| str[top]=='a' )  )
                  return false;
                  // 上述的情况都不满足时就执行退栈操作;
                  top--;
        }
        i++;
}
   if(top!=0) 
   return false;
   else
   return true;
}