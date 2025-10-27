typedef struct hashNode {
    int val;
    int cnt;
    UT_hash_handle hh;
} HNODE;

int majorityElement(int* nums, int numsSize){
    int i;
    HNODE *htable = NULL;
    for (i=0; i<numsSize; i++) {
        HNODE *tmp;
        HASH_FIND_INT(htable, &nums[i], tmp);
        if (!tmp) {
            tmp = (HNODE*)malloc(sizeof(HNODE));
            tmp->val = nums[i];
            tmp->cnt = 0;
            HASH_ADD_INT(htable, val, tmp);
        }
        tmp->cnt++;
        if (tmp->cnt > numsSize/2) return tmp->val;
    }
    return -1;
}