/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    * returnSize=rowIndex+1;
        int *returnarray;
        returnarray=(int *)malloc(sizeof(int)*(rowIndex+1));
        int i,j;
        returnarray[0]=1;
        for(i=1;i<=rowIndex+1;i++){
                returnarray[i-1]=1;
                for(j=i-2;j>=1;j--){
                    returnarray[j]=returnarray[j]+returnarray[j-1];
                    
                }
        }
        return returnarray;
}