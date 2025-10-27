char ** letterCombinations(char * digits, int* returnSize){
    char *s[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",};
    int a[] = {3,3,3,3,3,4,3,4,};
    int n=1,i=0,j=0,k=0,count=0;
    for(i=0;digits[i]!='\0';i++){
        if(digits[i]=='7' || digits[i]=='9'){
            n *=4;
        }else{
            n *=3;
        }
    }
    if(i == 0){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = n;
    char** result = (char**)malloc(sizeof(char*)*n);//二维数组的malloc，行与行之间不连续。
    for(j=0;j<n;j++){
        result[j] = (char*)malloc(sizeof(char)*(i+1));
        result[j][i] = '\0';//字符串末为0
    }
    count = n;
    for(i=0;digits[i]!='\0';i++){
        k = digits[i]-'0'-2;
        count /= a[k];
       for(j=0;j<n;j++){
           result[j][i] = s[k][(j/count)%a[k]];    //画一棵树就可以看出
       }
    }
    return result;
}