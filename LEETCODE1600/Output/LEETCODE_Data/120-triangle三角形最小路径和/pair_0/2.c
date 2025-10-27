int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int row, col;
    
    triangleColSize = (int *)malloc(triangleSize * sizeof(int));
    for (row = triangleSize - 1; row > 0; row--) {
        triangleColSize[row] = row + 1;
        for (col = 0; col <= row - 1; col++) {
            triangle[row - 1][col] += (triangle[row][col] < triangle[row][col + 1]) ? triangle[row][col] : triangle[row][col + 1];
        }
    }   
    return triangle[0][0];
}