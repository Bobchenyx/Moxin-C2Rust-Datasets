bool isMatch(char ch1, char ch2){
    if (ch1 == ')' && ch2 =='(')
        return true;
    if (ch1 == ']' && ch2 =='[')
        return true;
    if (ch1 == '}' && ch2 =='{')
        return true;
    else{
        return false;
    }
    
}
bool isRight(char ch3){
    if (ch3 ==')' || ch3 == ']' || ch3 == '}')
        return true;
    else
        return false;
}

bool isValid(char * s){
    int len = strlen(s);
    int index1 = 0;
    int i;
    while(s[index1] != '\0'){//数组没有全部扫描
        if (isRight(s[index1])){//如果属于右半边括号，那么从左扫描匹配
            i = index1-1;
            if ( i == -1){
                return false;
            }
            else if (s[i] == '\0'){
                while(i>=0 && s[i]== '\0'){
                    i--;
                }
                if (i<0){//溢出
                    return false;
                }
                if (!isMatch(s[index1], s[i])){//不匹配
                    return false;
                }
                else{
                    s[index1] = '\0';
                    s[i] = '\0';
                }
            }
            else{
                if (isMatch(s[index1], s[i])){
                    s[index1] = '\0';
                    s[i] = '\0';
                }
                else{
                    return false;
                }
            }
        }
        index1++;
    }
    i = 0;
    while (len--){//看着整个数组，是否全空
        if (s[i++] != '\0'){
            return false;
        }
    }
    return true;
    
}