void heapify(int *arrs, int n, int i) {
	if (i >= n) return;
	int max = i;  // 保存i值
	int lc = 2 * i + 1, rc = 2 * i + 2;  // 左右结点
	if (lc < n && arrs[lc] > arrs[max]) max = lc;  // 找最大
	if (rc < n && arrs[rc] > arrs[max]) max = rc;
	if (max != i) {
		lc = arrs[max];  // lc暂存arrs[max]值
		arrs[max] = arrs[i];
		arrs[i] = lc;
		heapify(arrs, n, max);  // 再生堆
	}
}

void heapsort(int *arrs, int n) {
	int i = (n - 1) >> 1, tmp;  // 非子叶结点
	for (; i >= 0; i--) heapify(arrs, n, i);
	for (i = n - 1; i >= 0; i--) {
		tmp = arrs[i];  // arrs[0]最大
		arrs[i] = arrs[0];
		arrs[0] = tmp;
		heapify(arrs, i, 0);
	}
}

int threeSumClosest(int* nums, int numsSize, int target){
    heapsort(nums, numsSize);  // 排序
    int closest = nums[0] + nums[1] + nums[2], threesum;
    short i, left, right;
    bool upgrade;
    for (i = 0; i < numsSize - 2; i++) {
        left = i + 1;
        right = numsSize - 1;
        upgrade = false;
        while (left < right) {
            threesum = nums[i] + nums[left] + nums[right];
            if (abs(target - threesum) < abs(target - closest)) {
                closest = threesum;
                upgrade = true;
            }
            if (threesum > target) {
                while (left < right && nums[right] == nums[right - 1])
                    right--;  // 右去重
                right--;  // 再左移1个
            }else if (threesum < target) {
                while (left < right && nums[left] == nums[left + 1])
                    left++;  // 左去重
                left++;  // 再右移1个
            }else  return closest;  // 相等，一定最优！
        }
        if (!upgrade&&nums[i]>0) return closest;  // 关键缩短循环判断
        while (i < numsSize - 2 && nums[i] == nums[i+1]) i++;
    }
    return closest;
}