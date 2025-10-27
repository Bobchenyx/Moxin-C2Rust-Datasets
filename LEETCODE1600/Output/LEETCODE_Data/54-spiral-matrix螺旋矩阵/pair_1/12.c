/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0){
        *returnSize=0;
        return NULL;
    }
    int *a=(int *)malloc(sizeof(int)*(matrixSize*(*matrixColSize)));
    int c=0;
    int up=0,down=matrixSize-1,left=0,right=*matrixColSize-1;
    while(up<=down&&left<=right){
        for(int i=left;i<=right;i++){
            a[c++]=matrix[up][i];
        }
        up++;
        if(up>down){
            break;
        }
        for(int i=up;i<=down;i++){
            a[c++]=matrix[i][right];
        }
        right--;
        if(left>right){
            break;
        }
        for(int i=right;i>=left;i--){
            a[c++]=matrix[down][i];
        }
        down--;
        if(up>down){
            break;
        }
        for(int i=down;i>=up;i--){
            a[c++]=matrix[i][left];
        }
        left++;
        if(left>right){
            break;
        }
    }
    *returnSize=c;
    return a;
}