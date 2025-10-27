bool validMountainArray(int* A, int ASize){
    if(ASize<3)
    return false;
    if(A[0]>=A[1]||A[ASize-1]>=A[ASize-2])//处理一下极端情况
    return false;
    int i;
    for(i=1;i<ASize-1;i++)
    if(A[i]>=A[i+1])//找到山峰
    break;
    for(i;i<ASize-1;i++)
    if(A[i]<=A[i+1])
    return false;
    return true;

}