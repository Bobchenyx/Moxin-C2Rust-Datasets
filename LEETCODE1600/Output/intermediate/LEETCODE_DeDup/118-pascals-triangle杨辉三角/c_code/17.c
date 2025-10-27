int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i,v,**arr;
    arr = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    *returnSize = numRows;

	for(int i=0;i<numRows;i++){
        (*returnColumnSizes)[i] = i+1; 
        arr[i] = (int *)malloc(sizeof(int)*(i+1));
        arr[i][0] = arr[i][i] = 1;
        for(int v=1;v < i;v++) arr[i][v] = arr[i-1][v-1] +arr[i-1][v];
	}
    return arr;
}