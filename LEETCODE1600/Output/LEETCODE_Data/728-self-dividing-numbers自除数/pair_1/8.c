/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    int cnt=0;
    int*num=(int*)malloc(sizeof(int)*(right-left+1));
    for(int i=left;i<=right;i++)
    {
        int temp=i;
        int flag=0;
        while(temp!=0)
        {
            if(temp%10==0||(i%(temp%10))!=0)
            {
                flag=1;
                break;
            }
            temp/=10;
        }
        if(flag!=1)
        num[cnt++]=i;
    }
    *returnSize=cnt;
    return num;
}