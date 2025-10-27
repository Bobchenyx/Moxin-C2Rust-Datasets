int min(int x,int y){
    return (x < y) ? x : y;
}


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int dp[triangleSize];
    int i,j;

    for(i = 0;i < triangleSize;i++){
        dp[i] = triangle[triangleSize-1][i];
    }


    for(i = triangleSize-2;i >= 0;i--){
        for(j = 0;j <= i;j++){
            dp[j] = min(triangle[i][j] + dp[j],triangle[i][j] + dp[j+1]);
        }
    }

    return dp[0];

}