#define min(a,b) (a<b?a:b)

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int i,j;
    if(triangle == NULL) return 0;
//自底向上
    for(i = triangleSize-2;i >= 0;i--){
        for(j = 0;j < triangleColSize[i];j++ ){
            triangle[i][j] = min(triangle[i+1][j],triangle[i+1][j+1])+triangle[i][j];
        }
    }
    return triangle[0][0];
}