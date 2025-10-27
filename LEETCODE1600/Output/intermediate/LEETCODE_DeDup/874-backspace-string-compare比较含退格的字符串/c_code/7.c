bool backspaceCompare(char * S, char * T) //双指针;
{ 
    int i = 0;
    int j = 0;
    char str[200],arry[200];
    while (S[j]) {  
        // 栈;
        if (S[j] == '#') {  // 再满足S[j]=="# 再满足 i>0 即可i-- ,目的为了防止i--为负使得str[i]越界;
              if(i>0)
                --i;
     
        }else 
        {
            str[i] = S[j];  // 由 0开始存入;
            i++;
        }
        ++j;
    } 
  str[i] = 0;
    i=j=0;
    while (T[j]) {
        if (T[j] == '#') {
           if (i > 0) --i;
        }else 
         {
             arry[i] = T[j];
             i++;
         }
        ++j;
    } 
    arry[i] = 0;
    return !strcmp(str ,arry);
}