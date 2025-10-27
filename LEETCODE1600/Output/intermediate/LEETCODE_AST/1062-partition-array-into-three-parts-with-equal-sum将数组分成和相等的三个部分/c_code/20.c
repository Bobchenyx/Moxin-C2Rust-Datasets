bool canThreePartsEqualSum(int* A, int ASize){
    if(ASize<3)
        return false;
    else{
    int sum=0,i=0,j=0,flag=0;
    for(i=0;i<ASize;i++)
        sum+=A[i];
    if(sum%3!=0)
        return false;
    else
        {
            sum=sum/3;
            for(i=0;i<ASize;i++)
            {
                j=j+A[i];
                if(j==sum)
                {
                    j=0;
                    flag++;
                }
            }
            if(flag>=3)
                return true;
            else
                return false;
        }
    }
}