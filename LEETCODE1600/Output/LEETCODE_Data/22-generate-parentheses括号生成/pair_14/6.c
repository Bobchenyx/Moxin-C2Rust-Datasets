void add_item(char** result, int* returnSize, char* str, int addr, int n, int k){
    if(n && !k){
        str[addr] = '(';
        add_item(result, returnSize, str, addr + 1, n - 1, k + 1);
    }else if(n && k){
        str[addr] = '(';
        add_item(result, returnSize, str, addr + 1, n - 1, k + 1);
        str[addr] = ')';
        add_item(result, returnSize, str, addr + 1, n, k - 1);
    }else if(!n && k){
        str[addr] = ')';
        add_item(result, returnSize, str, addr + 1, n, k - 1);
    }else if(!n && !k){
        //printf("%d %s\n", *returnSize, str);
        str[addr] = '\0';
        char* tmp = malloc(sizeof(char) * (addr + 1));
        memcpy(tmp, str, addr + 1);
        result[*returnSize] = tmp;
        *returnSize += 1;
    }
}

char ** generateParenthesis(int n, int* returnSize){
    //num = C(2n,n)/n
    int num = 1;
    for(int i = 1; i < n; i++){
        num *= (2 * n - i + 1);
        num /= i;
    }
    num /= n;
    num = num ? num : 1;
    //printf("%d\n",num);
    
    char** result = malloc(sizeof(char*) * (num));
    *returnSize = 0;
    char* str = malloc(sizeof(char) * (n * 2 + 1));
    memset(str, 0, (n*2+1));
    add_item(result, returnSize, str, 0, n, 0);
    //printf("%d\n",*returnSize);
    return result;
}