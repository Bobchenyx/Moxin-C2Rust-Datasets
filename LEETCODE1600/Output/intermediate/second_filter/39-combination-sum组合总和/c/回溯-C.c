/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int (*array)[1000][1000], int *solution, int left_num, int *candidates, int candidatesSize, int position, int chosen_num)
{
    int i;
    for(i = chosen_num; i < candidatesSize && candidates[i] < left_num; i++){
        (*array)[*solution][position + 1] = candidates[i];
        dfs(array,solution,left_num - candidates[i],candidates, candidatesSize, position + 1,i);
    }
    if(i < candidatesSize && candidates[i] == left_num){
        (*array)[*solution][position + 1] = candidates[i];
        (*array)[*solution][0] = position + 1;
        (*solution)++;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int i, j, tmp, k;
    for(i = 1; i < candidatesSize; i++){
        tmp = candidates[i];
        for(j = i-1; j >= 0 && candidates[j] > tmp; j--)
            candidates[j+1] = candidates[j];
        candidates[j+1] = tmp;
    }
    int array[1000][1000];
    int solution = 0;
    for(i = 0; i < 1000; i++)
        for(j = 0; j < 1000; j++)
            array[i][j] = 0;
    
    dfs(&array, &solution, target, candidates, candidatesSize, 0, 0);

    int **reval;
    *returnSize = solution;
    *returnColumnSizes = (int*)malloc(sizeof(int) * solution);
    reval = (int**)malloc(sizeof(int*) * solution);
    for(i = 0; i < solution; i++){
        (*returnColumnSizes)[i] = array[i][0];
        reval[i] = (int*)malloc(sizeof(int) * array[i][0]);
        for(j = 0; j < array[i][0]; j++){
            for(k = i; array[k][j+1] == 0; k--)
                continue;
            reval[i][j] = array[k][j+1];
        }
    }

    return reval;
}