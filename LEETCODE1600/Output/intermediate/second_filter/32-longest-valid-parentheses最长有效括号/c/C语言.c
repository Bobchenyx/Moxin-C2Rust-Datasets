int longestValidParentheses(char * s){
    int i = 0, maxLength = 0, left = 0, currentLength = 0, tempLength = 0;
    while (s[i] != '\0') {
        if(s[i] =='('){
            left++;
        }else{
            left--;
        }
        if(left < 0){
            currentLength = 0;
            tempLength = 0;
            
            left = 0;
        }else if(left == 0){
            tempLength++;
            currentLength = currentLength + tempLength;
        
            tempLength = 0;
            if(currentLength > maxLength){
                maxLength = currentLength;
            }
        }else{
            tempLength ++;
            if(s[i] ==')'){
                int leng = lengthOfAvailable(s, i);
                if(leng > maxLength){
                    maxLength = leng;
                }
            }
        }
        i++;
    }
    
    return maxLength;
}


int lengthOfAvailable(char *s, int index){
    int length = 0;
    int rightNum = 0;
    while (index > 0) {
        if(s[index] == ')'){
            rightNum ++;
        }else{
            rightNum --;
        }
        if(rightNum < 0){
            return length;
        }
        length++;
        index --;
    }
    return length;
}