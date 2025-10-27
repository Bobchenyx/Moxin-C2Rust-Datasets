//升序
int cmp(const void * _a, const void *_b){
    int * a = _a;
    int * b = _b;

    return *a - *b;
}

int longestValidParentheses(char * s){
    int i,j=0,len,top=0,temp_len=0,max_len=0;
    int *stack;
    int *arr;

    len = strlen(s);
    arr = malloc(len * sizeof(int));

    stack = (int *)malloc(len*sizeof(int));
    memset(stack,0,len*sizeof(int));

    for(i=0;i<len;i++){
        if(s[i] == '('){
            stack[top++] = i;
        }else if(top > 0){
            top--;
            arr[j++] = i;
            arr[j++] = stack[top];
        }
    }

    qsort(arr,j,sizeof(int),cmp);

    for(i=0;i<j-1;i++){
        if(arr[i+1] == arr[i]+1){
            temp_len++;
            if(temp_len > max_len)
                max_len = temp_len;
        }else{
            temp_len = 0;
        }
    }
    if(max_len)
        return max_len+1;
    else
        return max_len;
}