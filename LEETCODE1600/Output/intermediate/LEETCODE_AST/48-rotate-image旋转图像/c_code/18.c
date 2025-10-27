void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i = 0;
    int j = 0;
    int tempj = 0;
    int step = 0;
    int swap = 0;
    int source = 0;
    int m = 0;
    int M = 0;
    int n = 0;
    if(matrixSize == 1) {
        return;
    }
    if(matrixSize % 2 == 0) {
        M = matrixSize / 2 - 1;
    }
    else {
        M = (matrixSize - 1) / 2;
    }

    for(m = 0; m <= M; m++) {

    for(n = m; n < matrixSize - 1 - m; n++) {
        source = matrix[m][n];   
        i = m;
        j = n; 
        step = 0;
    while(step < 5) {
        swap = matrix[j][matrixSize - 1 - i];
        matrix[j][matrixSize - 1 - i] = source;
        source = swap;
        tempj = matrixSize - 1 - i;
        i = j;
        j = tempj;
        step++;
    }
    }
    }


    return;
}