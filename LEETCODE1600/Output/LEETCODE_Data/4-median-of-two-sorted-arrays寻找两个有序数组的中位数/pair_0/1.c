int compare(void const *a, void const *b){
    return *(int*)a - *(int*)b;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int len = nums1Size + nums2Size;
    int combine[len];
    memset(combine, 0, sizeof(combine));
    int i, j;
    for (i = 0; i < nums1Size; i++) {
        combine[i] = nums1[i];
    }
    for (j = 0; j < nums2Size; j++) {
        combine[nums1Size + j] = nums2[j];  
    }
    qsort(combine, len, sizeof(int), compare);
    if (len % 2 == 1) {
        return (double)combine[(len - 1) / 2];
    } else {
        return (double)((combine[(len - 1)/ 2] + combine[(len - 1)/ 2 + 1]) / 2.0);
    }
}