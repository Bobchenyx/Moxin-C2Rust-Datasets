double DoWhenOneNull(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int* arr;
	int n;

	if (nums1Size == 0) {
		arr = nums2;
		n = nums2Size;
	} else {
		arr = nums1;
		n = nums1Size;
	}

	if (n % 2) {
		return arr[n / 2];
	}

	if (n == 2) {
		return (double)(arr[0] + arr[1]) / 2;
	}

	return (double)(arr[n / 2 - 1] + arr[n / 2]) / 2;
}

// 求两个有序数组中第K小
int FindKMin(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
	int i = 0, j = 0, n = 0;

	while (i < nums1Size && j < nums2Size) {
		if (nums1[i] <= nums2[j]) {
			n += 1;
			if (n == k) {
				return nums1[i];
			}
			i += 1;
		} else {
			n += 1;
			if (n == k) {
				return nums2[j];
			}
			j += 1;
		}
	}

	int* arr;
	if (i == nums1Size) {
		if (n == k) {
			return nums1[nums1Size - 1];
		}
		arr = nums2;
	} else {
		if (n == k) {
			return nums2[nums2Size - 1];
		}
		arr = nums1;
	}

	int minLen = nums1Size < nums2Size ? nums1Size : nums2Size;
	return arr[k - minLen - 1];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	if (nums1Size == 0 || nums2Size == 0) {
		return DoWhenOneNull(nums1, nums1Size, nums2, nums2Size);
	}

	int k = (nums1Size + nums2Size) / 2;

	if ((nums1Size + nums2Size) % 2) {
		return FindKMin(nums1, nums1Size, nums2, nums2Size, k + 1);
	}

	int a = FindKMin(nums1, nums1Size, nums2, nums2Size, k);
	int b = FindKMin(nums1, nums1Size, nums2, nums2Size, k + 1);
	return (double)(a + b) / 2;
}