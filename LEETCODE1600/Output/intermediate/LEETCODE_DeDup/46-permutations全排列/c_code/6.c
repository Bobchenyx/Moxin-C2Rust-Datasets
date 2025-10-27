void helper(int* nums, int numsSize, int* visited, int* path, int **result, int index, int* reindex){
    for(int i=0;i<numsSize;i++){
        if(visited[i])  continue;
        path[index] = nums[i];
        visited[i] = 1;
        index += 1;
        if(numsSize == index) {
            result[*reindex]  = (int*) malloc(sizeof(int)*numsSize);
            for(int j=0;j<numsSize;j++){
                result[*reindex][j] = path[j];
            }
            *reindex = *reindex + 1;
        }
        helper(nums, numsSize, visited, path, result, index, reindex);
        visited[i] = 0;
        index -= 1;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int visited[numsSize];
    int path[numsSize];
    int index = 0;
    int reindex = 0;
    memset(visited, 0, sizeof(visited));
    int **result = (int**) malloc(sizeof(int*) * 10000);  
    helper(nums, numsSize, visited, path, result, index, &reindex);
    *returnSize = reindex;
    *returnColumnSizes = (int*) malloc(sizeof(int) * 10000);
    
    for(int i=0;i<reindex;i++){
        (*returnColumnSizes)[i] = numsSize; 
    }
    return result;
}