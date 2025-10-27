bool isValid(char * s){
    int count=0,pre[10000],n=0;     //count标记与右括号最近的左括号在数组pre中的位置，pre数组记录左括号在字符串中的位置
    for(int i=0;i<strlen(s);i++){   
        switch(s[i]){
            case '(':pre[count++]=i;break;
            case '{':pre[count++]=i;break;
            case '[':pre[count++]=i;break;
            case ')':if((--count)<0) return false;n=pre[count];if(s[n]!='(')  return false;break;
            case '}':if((--count)<0) return false;n=pre[count];if(s[n]!='{') return false;break;
            case ']':if((--count)<0) return false;n=pre[count];if(s[n]!='[') return false;break;
        }
    }
    if(count==0)
    return true;
    else
    return false;
}