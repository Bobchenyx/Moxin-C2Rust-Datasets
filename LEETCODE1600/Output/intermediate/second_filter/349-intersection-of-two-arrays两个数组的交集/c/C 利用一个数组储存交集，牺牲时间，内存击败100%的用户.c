C
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if(!nums1Size || !nums1Size) {
        *returnSize = 0;
        return 0;
    }
    int min = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *num = (int*)malloc(sizeof(int) * min);
    int count = 0;
    for(int i = 0; i < nums1Size; i++) {
        for(int j = 0; j < nums2Size; j++) {
            int flag =0;
            if(nums1[i] == nums2[j]) {
                for(int k = 0; k < min; k ++) {
                    if(num[k] == nums1[i])
                        flag = 1;
                }
                if(flag != 1)
                    num[count++] = nums1[i];
            }
        }
    }
    *returnSize = count;
    return num;
}