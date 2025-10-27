bool canThreePartsEqualSum(int* A, int ASize){
    for(int i=1;i<ASize;i++)
    {
        A[i]+=A[i-1];
    }
    if(A[ASize-1]%3!=0)
    {
        return false;
    }
    int oneOfThreeSum=A[ASize-1]/3;
    int twoOfThreeSum=oneOfThreeSum*2;
    int min_i=50000;
    int max_j=0;
    for(int i=0;i<ASize-1;i++)
    {
        if(A[i]==oneOfThreeSum && min_i==50000)
        {
            min_i=i;
        }
        else if(A[i]==twoOfThreeSum)
        {
            max_j=i;
        }

        if(max_j>min_i)
        {
            return true;
        }
    }
    return false;
}