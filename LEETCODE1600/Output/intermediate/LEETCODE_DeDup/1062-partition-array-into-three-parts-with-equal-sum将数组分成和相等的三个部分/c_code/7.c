//双指针
bool canThreePartsEqualSum(int* A, int ASize){
    int low=0,high=ASize-1;
    int sum1=A[low],sum2=A[high],sum=0;

    for(low;low<=high;low++)
    sum+=A[low];

    if(sum%3!=0)//是否是3的倍数
    return false;

    sum/=3;
    low=0;
        while(high-(low+1)>1&&sum1!=sum)
        sum1+=A[++low];
        while((high-1)-low>1&sum2!=sum)
        sum2+=A[--high];
    if(sum1==sum&&sum2==sum)
    return true;
    return false;
}