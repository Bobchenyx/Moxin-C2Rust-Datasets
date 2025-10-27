/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int arr[100][100] = {0};

int** dfs(int **image, int imageSize, int imageColSize, int sr, int sc, int newColor, int sourceColor){

    if (sr < 0 || sr >= imageSize || sc < 0 || sc >=imageColSize || arr[sr][sc] ==1) 
        return image;
    arr[sr][sc] = 1;
    if (image[sr][sc] == sourceColor){
        image[sr][sc] = newColor;
        dfs(image, imageSize, imageColSize, sr - 1, sc, newColor, sourceColor);
        dfs(image, imageSize, imageColSize, sr + 1, sc, newColor, sourceColor);
        dfs(image, imageSize, imageColSize, sr, sc - 1, newColor, sourceColor);
        dfs(image, imageSize, imageColSize, sr, sc + 1, newColor, sourceColor);
    }

    return image;
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    int i = 0;

    memset(arr, 0, 10000*sizeof(int));
    *returnSize = imageSize;
    *returnColumnSizes = malloc(imageColSize[0] * sizeof(int));
    for (i = 0; i < imageSize; i++)
        (*returnColumnSizes)[i] = imageColSize[0];
    //printf("%d %d\n",sc, sc, image[sr][sc])

    return dfs(image, imageSize, imageColSize[0], sr, sc, newColor, image[sr][sc]);
}