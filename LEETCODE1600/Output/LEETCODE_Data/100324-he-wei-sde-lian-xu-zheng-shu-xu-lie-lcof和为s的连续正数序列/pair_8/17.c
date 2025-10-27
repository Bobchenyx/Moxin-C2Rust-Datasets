/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */





int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes)
{
    int** ans=(int**)malloc(sizeof(int*)*(target/2));
    * returnColumnSizes=(int*)malloc(sizeof(int)*(target/2));
    int l=1;int r=2;
    int i=0;
    int val=0;
    while(l<r)
    {
        int sum=(l+r)*(r-l+1)/2;
        if(sum==target)
        {
            ans[i]=(int*)malloc(sizeof(int)*(r-l+1));
            val=l;
            for(int j=0;j<(r-l+1);j++)
            {
                ans[i][j]=val;
                val++;
            }
            (*returnColumnSizes)[i]=r-l+1;
            i++;
            l++;   
        }
        else if(sum<target) r++;
        else l++;
    }
    *returnSize=i;
    return ans;
}