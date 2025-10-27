/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i;
	//处理全部为9的情况
    int* newdigits = (int *)malloc(sizeof(int) * (digitsSize+1));
    for (i = 0; i < digitsSize + 1; i++)
			newdigits[i] = 0;
	for (i = digitsSize - 1; i >= 0; i--) {
		if (digits[i] == 9) {
			digits[i] = 0;
		}
		else {
			digits[i] += 1;
            *returnSize = digitsSize;
			return digits;
		}
	}
	if (i == -1) {
		newdigits[0] = 1;
	}
	*returnSize = digitsSize + 1;
	return newdigits;
}