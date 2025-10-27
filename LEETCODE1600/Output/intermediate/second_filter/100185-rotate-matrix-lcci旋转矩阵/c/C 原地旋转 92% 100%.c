void swap(int *a,int *b){
    int temp=0;
    temp=*a;
    *a=*b;
    *b=temp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize!=matrixColSize[0]) return ;
    if(matrixSize<2) return ;
    int n=matrixSize-1;
    for(int i=0;i<(matrixSize+1)/2;i++){
        for(int j=i;j<n;j++){
            swap(&matrix[i][j],&matrix[n-j+i][i]);         //
            swap(&matrix[n-j+i][i],&matrix[n][n-j+i]);     //
            swap(&matrix[n][n-j+i],&matrix[j][n]);         //核心公式
        }
        n--;
    }
}