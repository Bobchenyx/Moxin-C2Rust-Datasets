/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int end=target/2;
    int retsize=0;
    int *retcolsize=(int*)malloc(sizeof(int)*end);
    int **output=(int**)malloc(sizeof(int*)*end);
    int iop=0;
    for(int i=1;i<=end;i++){
        int sum=0;int jcount=0;int j;
        for(j=i;;j++){
            sum+=j;
            jcount++;
            if(sum>=target){
                break;
            }
        }
        if(sum==target){//如果得到了结果，才分配空间
            output[iop]=(int*)malloc(sizeof(int)*(jcount));
            int ii=0;
            for(int k=i;k<=j;k++){
                output[iop][ii++]=k;
            }
            retcolsize[iop]=jcount;
            iop++;
            retsize++;
        }
    }
    *returnColumnSizes=retcolsize;
    *returnSize=retsize;
    return output;
}