int Cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{    
    int i;
    double returnVal = 0.0;
    int *numsFinal = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
    memcpy(numsFinal, nums1, nums1Size * sizeof(int));
    memcpy(&(numsFinal[nums1Size]), nums2, nums2Size * sizeof(int));
    qsort(numsFinal, (nums1Size + nums2Size), sizeof(numsFinal[0]), Cmp);
    if (((nums1Size + nums2Size) % 2) != 0) {
        return numsFinal[(nums1Size + nums2Size) / 2] / 1.0;
    } else {
        return (numsFinal[(nums1Size + nums2Size) / 2] +numsFinal[(nums1Size + nums2Size) / 2 - 1]) / 2.0;
    }
}