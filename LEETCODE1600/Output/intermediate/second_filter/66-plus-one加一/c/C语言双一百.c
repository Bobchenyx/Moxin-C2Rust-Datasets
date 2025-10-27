int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * (digitsSize+1));
    if(digits[digitsSize-1]>=0 && digits[digitsSize-1]<9){
        digits[digitsSize-1] +=1;
        *returnSize = digitsSize;
        return digits;
    }
    else{
        int k = digitsSize-1;
        while(k>=0 && digits[k] == 9){
            digits[k] = 0 ;
            k--;
        }
        if(digits[0] == 0){
            
            arr[0] = 1;
            for(int i = 1 ; i <= digitsSize ;i++) arr[i] = 0 ;
            *returnSize = digitsSize+1;
            return arr;
        }else{
            digits[k] ++;
            *returnSize = digitsSize;
        }
    }
    return digits;
}