/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int i,j,sum=0;
    int start,end;
    int **arr=(int**)malloc(sizeof(int*)*10000);
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*1000);
    start=1;end=1;
    *returnSize=0;
    for(i=1;i<target;i++){
        sum+=i;end=i;
        if(target==sum){
            arr[*returnSize]=(int*)malloc(sizeof(int)*(target+1));
            for(j=start;j<=end;j++){
                arr[*returnSize][j-start]=j;
            }
            (*returnColumnSizes)[*returnSize]=end-start+1;
            (*returnSize)++;
        }
        else if(sum>target){
            while(sum>target){
                sum-=start;
                start++;
            }
            if(target==sum){
                arr[*returnSize]=(int*)malloc(sizeof(int)*(target+1));
                for(j=start;j<=end;j++){
                    arr[*returnSize][j-start]=j;
                }
                (*returnColumnSizes)[*returnSize]=end-start+1;
                (*returnSize)++;
            }
        }
    }
    return arr;
}