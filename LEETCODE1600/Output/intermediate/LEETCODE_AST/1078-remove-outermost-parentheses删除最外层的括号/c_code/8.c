char * removeOuterParentheses(char * S){
    int count = 0 , k = 0,i=0;
   while(S[i]!='\0') {
        if(S[i] == '('){
            if(count != 0) 
            {
                S[k] = S[i];
                k++;
            }
            count++;
        }
        if(S[i] == ')'){
            count--;
            if(count != 0)
            {

             S[k] = S[i];
             k++;
            }
        }
        i++;
    }
    S[k] = '\0'; // 添加结束标志;
    return S;
}