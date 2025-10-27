char * reverseParentheses(char * s){
    if(!s) return NULL;
    int len = strlen(s);
    int leftIndex[len];

    int i = 0;
    int idx = -1;
    while(s[i]){
        if(s[i] == '('){
            leftIndex[++idx] = i;//遇到"("则下标入栈
        }
        else if(s[i] == ')'){
            int left = leftIndex[idx] + 1;
            int right = i -1;
            while(left < right){
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++, right--;
            }
            idx--;
        }
        i++;//使用while循环时，别忘了更新下标
    }
    char *res = (char *)malloc((len + 1) * sizeof(char));
    memset(res, '\0', (len + 1) * sizeof(char));
    i = 0;
    int j = 0;
    while(s[i]){
        if(s[i] != '(' && s[i] != ')'){
            res[j] = s[i];
            j++;
        }
        i++;
    }
    return res;
}