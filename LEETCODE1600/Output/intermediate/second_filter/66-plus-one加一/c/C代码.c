/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){

    for (int i = digitsSize - 1; i >= 0; i--) {

		digits[i] = digits[i] + 1;
		if (digits[i] % 10 != 0) {

			for (int j = i; i < digitsSize - 1; i++) {

				digits[i + 1] = 0;
			}

			* returnSize = digitsSize;
			return digits;
		}
	}

	int *result = (int*)malloc(sizeof(int*) * digitsSize + 1);

	result[0] = 1;
	for (int i = 1; i < digitsSize + 1; i++) {

		result[i] = 0;
	}
    
    * returnSize = digitsSize + 1;
	return result;
}