#include <string.h>

bool isValid(char * s){
    char st[100000];
    int cnt = 0,len = strlen(s);
    for(int i = 0;i < len;i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st[cnt] = s[i];
            cnt++;
        }
        if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            //ASCII表中，左括号与它对应的右括号ASCII值相差不超过二
            //  ( 是 40     ) 是 41
            //  [ 是 91     ] 是 93
            //  { 是 123    } 是 125
            if((cnt-1 >= 0) && (st[cnt-1] - s[i] < 0) && (st[cnt-1] - s[i] >= -2))
                cnt--;
            else return false;
        }
    }
    if(cnt == 0)    return true;
    return false;
}