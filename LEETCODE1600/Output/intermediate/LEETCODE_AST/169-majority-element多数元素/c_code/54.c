第一种
typedef struct hNode {
    int val;
    int cnt;
    UT_hash_handle hh;
} hNode;

int majorityElement(int* nums, int numsSize){
    int i;
    hNode *htable = NULL;
    for (i=0; i<numsSize; i++) {
        hNode *tmp;
        HASH_FIND_INT(htable, &nums[i], tmp);
        if (!tmp) {
            tmp = (hNode*)malloc(sizeof(hNode));
            tmp->val = nums[i];
            tmp->cnt = 0;
            HASH_ADD_INT(htable, val, tmp);
        }
        tmp->cnt++;
        if (tmp->cnt > numsSize/2) return tmp->val;
    }
    return -1;
}

第二种：
int compare (const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
    }


int majorityElement(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),compare);

    return nums[numsSize/2];
}