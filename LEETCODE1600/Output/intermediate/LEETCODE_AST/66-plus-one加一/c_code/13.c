/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
	int *result = malloc(sizeof(int) * (digitsSize + 1));
	int *result2 = malloc(sizeof(int) * (digitsSize));
	memset(result, 0, sizeof(int) * (digitsSize + 1));
	memset(result2, 0, sizeof(int) * (digitsSize));

	int in = 0;
	int temp = 0;
	temp = 1;

	for (int i = digitsSize - 1; i >= 0; i--) {
		temp = temp + digits[i];
		if (temp >= 10) {
			result[i + 1] = temp - 10;
			temp = 1;
		}else{
			result[i+1] = temp;
			temp = 0;
		}
	}
	if (temp ==1){
		result[0]=1;
		*returnSize = digitsSize+1;
		free(result2);
		return result;
	}else{
		*returnSize = digitsSize;
		memcpy(result2,result+1,digitsSize*sizeof(int));
		free(result);
		return result2;
	}
}