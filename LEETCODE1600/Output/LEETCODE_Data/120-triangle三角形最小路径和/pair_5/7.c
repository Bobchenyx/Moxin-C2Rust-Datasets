#define MIN(a,b) ((a)<(b)?(a):(b))
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int *arr = (int *)malloc(sizeof(int)*triangleSize);
    memcpy(arr,triangle[triangleSize-1],sizeof(int) *triangleSize);

    int j ,k;
    for(j = triangleSize - 2;j >= 0;j--)
        for(k = 0; k <= j; k++) 
            arr[k] = triangle[j][k] + MIN(arr[k],arr[k+1]);
    return *arr;
}