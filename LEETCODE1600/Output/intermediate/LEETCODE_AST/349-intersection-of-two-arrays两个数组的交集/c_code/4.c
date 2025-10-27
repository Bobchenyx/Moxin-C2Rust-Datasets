/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int temp = nums1Size > nums2Size ? nums2Size : nums1Size;
    int *arr = (int*)malloc(sizeof(int)*temp);
    int size = 0;
    for ( int i = 0 ; i < nums1Size ; i++ ) {
        for ( int j = 0 ; j < nums2Size ; j++ ) {
            if ( nums2[j] == nums1[i] ) {
                int flag = 0;
                for ( int k = 0 ; k < size ; k++ ) {
                    if ( arr[k] == nums2[j] ) {
                        flag = 1;
                    }
                }
                if ( !flag ) {
                    arr[size++] = nums2[j];
                }
            }
        }
    }
    (*returnSize) = size;
    return arr;
}