/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(void * a, void * b){
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, l, r, sum, k=0;
    int res[20000][3] = {0};
    int **ret;

    qsort(nums, numsSize, sizeof(int), cmp);
    for (i = 0; i < numsSize - 2; i++) {
        if (i != 0 && nums[i] == nums[i-1])
            continue;

        l = i + 1;
        r = numsSize - 1;
        while (l < r) {
            sum = nums[i] + nums[r] + nums[l];
            if (sum == 0) {
                res[k][0] = nums[i];
                res[k][1] = nums[l];
                res[k++][2] = nums[r];
                l++,r--;
                while(l < r && nums[l] == nums[l-1])
                    l++;
                while (r > l && nums[r] == nums[r+1]) 
                    r--;
            }
  
            if (sum > 0)
                r--;
            else if(sum < 0)
                l++;
        }
    }
    ret = malloc(k*sizeof(char*));
    int *retcol = malloc(k*sizeof(int)); 
    for (i = 0; i < k; i++) {
        ret[i] = malloc(3*sizeof(int));
        ret[i][0] = res[i][0];
        ret[i][1] = res[i][1];
        ret[i][2] = res[i][2];
        retcol[i] = 3;
    }
    *returnColumnSizes = retcol;
    *returnSize = k;
    return ret;
}