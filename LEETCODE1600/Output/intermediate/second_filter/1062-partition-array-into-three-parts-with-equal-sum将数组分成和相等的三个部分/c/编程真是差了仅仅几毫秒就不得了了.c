bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0 , i , num =0;
    for(i = 0; i < ASize; i++ )  sum += A[i];
    if(sum % 3) return false;
    int avg = sum/3;
    sum = 0;
    for(i = 0; i < ASize; i++ )
    {
        sum += A[i];
        if(sum == avg)
        {
            num ++;
            if(num == 3)
            {   //判断有三个均值后的数是否为 0  列[3,3,3,3,-3];
                if(i = ASize - 1)
                    return true;
                for(i = i+1; i < ASize; i++  )
                    sum += A[i];
                if(sum == 0)   return true;
            }
            sum = 0;
        }
    }
    return num == 3;
}