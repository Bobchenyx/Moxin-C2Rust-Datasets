/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    bool c = false;//进位标志
    digits[digitsSize-1]+=1;
    *returnSize=digitsSize;
    for(int i=digitsSize-1;i>=0;i--){
        if(c)digits[i]+=1;
        if(digits[i]>9){
            c=true;
            digits[i]=0;
        }else c=false;
    }
    if(c){
        *returnSize=digitsSize+1;
        printf(" %d",*returnSize);
        int* arr = (int*)malloc(sizeof(int)*(*returnSize));
        arr[0]=1;
        for(int i=1;i<*returnSize;i++)
            arr[i]=digits[i-1];
        return arr;
    }
    return digits;
}