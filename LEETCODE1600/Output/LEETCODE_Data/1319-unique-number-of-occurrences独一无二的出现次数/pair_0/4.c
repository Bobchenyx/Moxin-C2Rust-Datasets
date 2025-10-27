bool uniqueOccurrences(int* arr, int arrSize){
	char hash[2000] = {0}, set[1000] = {0};
	for (short i = 0; i < arrSize; i++) hash[arr[i]+1000]++;
	for (short i = 0; i < 2000; i++) {
		if (hash[i] > 0 && set[hash[i]] > 0) return false;
		else set[hash[i]] = 1;
	}
	return true;
}