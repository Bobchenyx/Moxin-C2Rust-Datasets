/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){

    int i=digitsSize-1;
    int carry=0;
    *returnSize=digitsSize;
    digits[i]++;
    while(i>=0){
        if((digits[i]+carry)/10){
            carry=1;
            digits[i]=0;
        }else{
            digits[i]+=carry;
            return digits;
        } 
        i--;
    }
    (*returnSize)++;
    int* result=(int*)malloc(sizeof(int)*(*returnSize));
    *(result++)=1;
    memcpy(result,digits,sizeof(int)*digitsSize);
    return --result;
}