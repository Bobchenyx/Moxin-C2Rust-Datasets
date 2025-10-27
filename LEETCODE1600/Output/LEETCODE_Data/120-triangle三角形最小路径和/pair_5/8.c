int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){


    //由于不需要保存所有的状态，而且当前状态只和上一状态有关
    //因此只需要一个一维数组
    int *res = (int*)malloc(sizeof(int) * triangleColSize[triangleSize-1]);
    //结果最后一行就是原来的最后一行
    memcpy(res, triangle[triangleSize - 1], 
                sizeof(int) * triangleColSize[triangleSize-1]);
    //从最后第2行开始递推
    for (int i = triangleSize - 2; i >= 0 ; i-- ){
        //为新的行分配内存
        for ( int j = 0 ; j < triangleColSize[i]; j++){
            //第(i,j)元素的值为(i+1,j), (i+1,j+1)中的最小值
            int min =  res[j] < res[j+1] ?res[j] : res[j+1];
            res[j] = triangle[i][j] + min;

        }
    }
    return res[0];

}