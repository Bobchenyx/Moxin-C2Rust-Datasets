static int m_cmp(const void *x, const void *y)
{
    return (*(int *)x - *(int *)y);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    memcpy(nums1 + m, nums2, sizeof(int) * n);
    qsort((void *)nums1, m + n, sizeof(int), m_cmp);
}