int* diStringMatch(char* S, int* returnSize){
    int char_size = strlen(S);
    int k = char_size;
    int j = 0;
    *returnSize = char_size + 1;
    int* ret = malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize ; i ++){
        if(S[i]=='D'){
             ret[i] = k--;
        }else{
             ret[i] = j++;
        }
    }
    return ret;
}