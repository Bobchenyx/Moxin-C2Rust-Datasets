int calcFactorial( int l) {
	if (l == 0 || l == 1) {
		return 1;
	}
	return l * calcFactorial(l - 1);
}


char * getPermutation2(int n, int k) {

	char *result = (char *)malloc(n + 1);
	result[n] = '\0';

	int nums[9] = { 0 };
	for (int i = 0; i < n; i++) {
		nums[i] = i + 1;
	}
	
	int index, value = k - 1, temp = n;
	for (int i = 0; i < n;i++) {
		index = value / calcFactorial(n - i - 1);
		value = value % calcFactorial(n - i - 1);
		result[i] = nums[index] + '0';
		
		if (index != temp - 1) {
			memmove(nums + index, nums + index + 1, (temp - index - 1) * sizeof (int));
		}
		temp--;
	}
	return result;
}