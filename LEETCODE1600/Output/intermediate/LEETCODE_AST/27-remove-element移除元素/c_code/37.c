void BubbleSort(int *A, int len){
    for(int i=0;i<len-1;i++){
        int flag=1;
        for(int j=len-1;j>i;j--){
            if(A[j]<A[j-1]){
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                flag=0;
            }
        }
        if(flag==1)
            return;
    }
}

int removeElement(int* nums, int numsSize, int val) {
    
	BubbleSort(nums, numsSize);
	int left = 0, right = numsSize, mid;
	int l = -1, r = -1;
	//第一个二分法来找左边界
	while (left < right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == val) {
			right = mid;
			l = mid;
		}
		else if (nums[mid] > val) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	left = 0;
	right = numsSize;
	//第二个二分法找右边界
	while (left < right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == val) {
			left = mid+1;
			r = mid;
		}
		else if (nums[mid] < val) {
			left = mid+1;
		}
		else {
			right = mid;
		}
	}
	//存在无查找元素的情况，这时候可直接返回numsSize，不需要和下面一样再对l和r赋值
	if (l == -1 && r == -1) {
		l = 0;
		r = 0;
	}
	else
		r++;
	int len = l;
	while (r < numsSize) {
		nums[len] = nums[r];
		len++;
		r++;
	}
	return len;
}