int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i=digitsSize-1;
    int overflowFlag=1;
    while(i>=0){
        //情况1
        if(digits[i]<9){
            digits[i]++;
            overflowFlag=0;
            break;
        }
        //情况2
        else{
            digits[i]=0;
            i--;
        }
    }
    int* result=NULL;
    //情况4
    if(overflowFlag){
        *returnSize=digitsSize+1;
        result=(int*)malloc(sizeof(int)*(digitsSize+1));
        result[0]=1;
        for(int i=0;i<digitsSize;i++){
            result[i+1]=0;
        }
    }
    //情况3
    else{
        *returnSize=digitsSize;
        result=digits;
    }
    return result;
}