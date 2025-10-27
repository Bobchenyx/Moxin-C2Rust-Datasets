bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
        if (matrix == 0 || matrixSize == 0 || matrixColSize[0] == 0) return false;
        //右上角开始
        int i = 0 , j = matrixColSize[i]-1;
        //到左下角终止
        while(i <matrixSize && j >= 0)
            if(matrix[i][j] == target)
                return true;
            //如果当前元素大于目标值，说明当前元素的下边的所有元素都一定大于目标值，因此往下查找不可能找到目标值，往左查找可能找到目标值。
            else if(matrix[i][j] > target)
                j--;
            //如果当前元素小于目标值，说明当前元素的左边的所有元素都一定小于目标值，因此往左查找不可能找到目标值，往下查找可能找到目标值
            else
                i++;
        return false;
}