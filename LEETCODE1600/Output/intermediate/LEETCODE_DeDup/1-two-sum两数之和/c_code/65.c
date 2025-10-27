typedef struct tagDataInfoS {
    int num;
    int idx;
}DataInfo;

int DataInfoCmp(const void* d1, const void* d2)
{
    DataInfo* data1 = (DataInfo*)d1;
    DataInfo* data2 = (DataInfo*)d2;
    
    if (data1->num > data2->num) {
        return 1;
    }
    return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    DataInfo* array;
    DataInfo* left;
    DataInfo* right;
    int* result;
    
    if (nums == NULL || numsSize < 2) {
        *returnSize = 0;
        return NULL;
    }
    
    array = (DataInfo*)malloc(numsSize * sizeof(DataInfo));
    if (array == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    for (i = 0; i < numsSize; i++) {
        array[i].num = nums[i];
        array[i].idx = i;
    }
    
    qsort(array, numsSize, sizeof(DataInfo), DataInfoCmp);
    
    left = &array[0];
    right = &array[numsSize - 1];
    
    do {
        if (left->num + right->num == target) {
            result = (int*)malloc(2 * sizeof(int));
            if (result == NULL) {
                free(array);
                *returnSize = 0;
                return NULL;
            }
            *returnSize = 2;
            result[0] = left->idx;
            result[1] = right->idx;
            free(array);
            return result;
        } else if (left->num + right->num > target) {
            right--;
        } else {
            left++;
        }
    } while (left != right);
    
    free(array);
    *returnSize = 0;
    return NULL;
}