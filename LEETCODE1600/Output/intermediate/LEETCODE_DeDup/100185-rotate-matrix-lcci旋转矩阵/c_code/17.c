void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int k, step, index, temp;
    for(step=matrixSize-1, index=0; step>0; step-=2, index++){
        for(k=0; k<step; k++){
            temp = matrix[index][index+k];
            matrix[index][index+k] = matrix[index+step-k][index];
            matrix[index+step-k][index] = matrix[index+step][index+step-k];
            matrix[index+step][index+step-k] = matrix[index+k][index+step];
            matrix[index+k][index+step] = temp;
        }
    }
}