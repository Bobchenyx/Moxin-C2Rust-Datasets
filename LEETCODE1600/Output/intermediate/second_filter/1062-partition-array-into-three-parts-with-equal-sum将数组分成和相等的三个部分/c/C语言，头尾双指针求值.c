bool canThreePartsEqualSum(int* A, int ASize)
{
    int sum=0;
    int presum=0;//切记不要在循环内给变量赋初值。
    int tailsum=0;
    for(int i=0;i<ASize;i++)
        sum+=A[i];
    if(sum%3)
        return false;
    for(int i=0;i<ASize-2;i++)
    {
        
        presum+=A[i];
        if(presum==(sum/3))
        {
            for(int j=ASize-1;j>1;j--)
            {
                
                tailsum+=A[j];
                if((j>i+1)&&tailsum==(sum/3))
                    return true;
            }
        }
    }
    return false;

}