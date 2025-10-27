int* plusOne(int* digits, int digitsSize, int* returnSize){
    short i=digitsSize-1,from_lower=1;
    while(from_lower&&i>=0){
        digits[i]=digits[i]+from_lower;
        if(digits[i]>9) digits[i]=digits[i]-10;
        else from_lower=0;
        i--;
    }
    *returnSize=digitsSize+from_lower;
    int* res=malloc(*returnSize*sizeof(int));
    for(i=0;i<digitsSize;i++) res[i+from_lower]=digits[i];
    if(from_lower) res[0]=1;
    return res;
}