bool canThreePartsEqualSum(int* A, int ASize){
    int sum=0,i,ret,total=0;
    for(i=0;i<ASize;i++)
    sum+=A[i];
    if(sum%3!=0)
    return false;
    for(i=0,ret=0;i<ASize;i++)
    {
        if(ret==2)
        return true;
        total+=A[i];
        if(total==sum/3)
        {
            ret++;
            total=0;
        }
    }
    return false;
}