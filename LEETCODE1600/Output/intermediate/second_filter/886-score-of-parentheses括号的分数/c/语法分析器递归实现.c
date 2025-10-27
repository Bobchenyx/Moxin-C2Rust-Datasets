int scoreOfParentheses(char * S){
    int left = 0;
    int sum = 0;

    if('(' != *S){
        return 0;
    }
    if('(' == *S && '(' == *(S+1)){
        left = 1;
        sum = 2*scoreOfParentheses(S+1);        
    }
    if('(' == *S && ')' == *(S+1)){
        left = 1;
        sum = 1;
    }
    //find this exp end;
    while(left && *(++S)){
        if('(' == *S){
            left++;
        }
        if(')' == *S){
            left--;
        }
        if(!left)
            break;
    }
    return sum + scoreOfParentheses(S+1);
}