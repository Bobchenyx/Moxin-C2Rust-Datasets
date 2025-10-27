bool canThreePartsEqualSum(int* A, int ASize){
    int sum=0;
    int i;
    for(i=0;i<ASize;i++)
        sum+=A[i];
    if(sum%3!=0) return false;
    int sum1=0;
    int count=0;
    for(i=0;i<ASize;i++)
    {   
        sum1+=A[i];
        if(sum1==(sum/3)){
            sum1=0;
            count++;
            if(count==2&&i<ASize-1) return true;
        }
    }
    return false;
}