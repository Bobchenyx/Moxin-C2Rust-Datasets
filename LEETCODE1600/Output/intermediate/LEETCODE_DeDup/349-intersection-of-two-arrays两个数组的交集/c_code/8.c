/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int com(int *a, int *b){
    return *a - *b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i, j, k=0;
    int *res = malloc(nums1Size * sizeof(int));

    if(nums1Size == 0 || nums2Size == 0){
        *returnSize = 0;
        return NULL;
    }
    qsort(nums1, nums1Size, sizeof(int), com);

    for(j=0;j < nums2Size; j++) {
                if(nums1[0] == nums2[j])
                    break;
    }
    if(j < nums2Size)
        res[k++] = nums1[0];

    for (i=1; i < nums1Size; i++) {
        if (nums1[i] != nums1[i-1]) {
            for(j=0;j < nums2Size; j++) {
                if(nums1[i] == nums2[j])
                    break;
            }
            if(j < nums2Size)
                res[k++] = nums1[i];
        }
    }
    *returnSize = k;
    return res;
}