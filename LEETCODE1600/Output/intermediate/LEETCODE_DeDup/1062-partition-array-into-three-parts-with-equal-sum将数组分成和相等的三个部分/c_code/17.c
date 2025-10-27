bool canThreePartsEqualSum(int* A, int ASize){
    //先找出平均值
    int avg = 0;
    for(int i = 0; i < ASize; i++)
    {
        avg += A[i];
    }
    if(avg % 3 != 0)
        return false;
    avg = avg/3;
    int index = 0;
    int sum = 0;
    for(int i = 0; i <= 2; i++)
    {
        int flag = 0;
        for(; index < ASize; index++)
        {
            sum += A[index];
            if(sum == avg)
            {
                flag = 1;
                index += 1;
                sum = 0;
                break;
            }  
        }
        if(flag == 0)
            return false;
    }
    return true;
}