double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int left=0, right=0;
	int len = nums1Size+nums2Size;
	int ret[len];
	memset(ret, 0, sizeof(int)*(len));
	int i=0;
	while((left<nums1Size)&&(right<nums2Size)){
		if (nums1[left]<nums2[right]){
			ret[i] = nums1[left];
			left++;
		}else{
			ret[i] = nums2[right];
			right++;
		}
		i++;
	}
	

	while(right<nums2Size && i<len){
		ret[i] = nums2[right];
		i++;
		right++;
	}

	while(left<nums1Size&& i<len){
		ret[i] = nums1[left];
		i++;
		left++;
	}
	
	
	if(len%2==0){
		return ((ret[len/2]+ret[len/2-1])/2.0);
	}else{
		return ret[len/2];
	}
}