bool findNumByCro(int** matrix, int matrixSize, int* matrixColSize, int cross, int target)
{
    if (cross == matrixSize || cross == *matrixColSize || matrix[cross][cross] > target) {
        return false;
    }
    
    if (matrix[cross][cross] == target) return true;
    
    if (findNumByCro(matrix, matrixSize, matrixColSize, cross + 1, target)) {
        return true;
    } else {
        for (int i = cross; i < matrixSize; i++) {
            if (matrix[i][cross] > target) break;
            if (matrix[i][cross] == target) return true;
        }
        
        for (int j = cross; j < *matrixColSize; j++) {
            if (matrix[cross][j] > target) break;
            if (matrix[cross][j] == target) return true;
        }
        return false;
    }
}

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }
    if (matrix[0][0] > target) {
        return false;
    }
    
    return findNumByCro(matrix, matrixSize, matrixColSize, 0, target);  
}