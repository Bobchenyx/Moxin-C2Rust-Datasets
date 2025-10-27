int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0){
        *returnSize = 0;
        return;
    }

    int visited = INT_MIN;
    int rows = matrixSize;
    int cols = matrixColSize[0];
    *returnSize = rows*cols;
    int *res = (int *)calloc(*returnSize,sizeof(int));
    int index=0;
    int direction = 1;//1--right, 2--down, 3--left, 4-up
    int i=0,j=0;
    while(index!=(*returnSize)){
        if(direction==1){//go right
            while(j<cols && matrix[i][j]!=visited){
                res[index++] = matrix[i][j];
                matrix[i][j] =visited;
                j++;
            }
            j--;
            i++;
            direction=2;
        }else if(direction==2){//go down
            while(i<rows && matrix[i][j]!=visited){
                res[index++] = matrix[i][j];
                matrix[i][j] =visited;
                i++;
            }
            i--;
            j--;
            direction=3;            
        }else if(direction==3){//go left
            while(j>=0 && matrix[i][j]!=visited){
                res[index++] = matrix[i][j];
                matrix[i][j] =visited;
                j--;
            }
            j++;
            i--;
            direction=4; 
        }else if(direction==4){//go up
            while(i>=0 && matrix[i][j]!=visited){
                res[index++] = matrix[i][j];
                matrix[i][j] =visited;
                i--;
            }
            i++;
            j++;
            direction=1; 
        }
    }

    


    return res;
}