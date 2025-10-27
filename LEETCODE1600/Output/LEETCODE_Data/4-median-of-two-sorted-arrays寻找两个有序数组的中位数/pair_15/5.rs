func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var len1, i = len(nums1), 0
	var len2, j = len(nums2), 0
	var flag, b = 0, false
	if 0 == (len1+len2)%2 {
		flag = 1
	}
	var ans float64
	for k := 0; k < len1+len2; k++ {
		if b {
			break
		}
		if j == len2 || (i < len1 && j < len2 && nums1[i] < nums2[j]) {
			if flag == 1 && (k == (len1+len2)/2 || k == (len1+len2)/2-1) {
				ans += float64(nums1[i]) / 2.0
				if k == (len1+len2)/2 {
					b = true
				}
			} else if flag == 0 && k == (len1+len2)/2 {
				ans = float64(nums1[i])
				b = true
			}
			i++
			continue
		}
		if i == len1 || (i < len1 && j < len2 && nums2[j] <= nums1[i]) {
			if flag == 1 && (k == (len1+len2)/2 || k == (len1+len2)/2-1) {
				ans += float64(nums2[j]) / 2.0
				if k == (len1+len2)/2 {
					b = true
				}
			} else if flag == 0 && k == (len1+len2)/2 {
				ans = float64(nums2[j])
				b = true
			}
			j++
		}
	}

	return ans
}