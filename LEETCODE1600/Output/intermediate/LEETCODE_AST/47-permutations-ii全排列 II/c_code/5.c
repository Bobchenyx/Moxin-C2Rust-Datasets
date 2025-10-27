/**
* 计算 n 的 阶乘
*/
int clcNFactory(int n) {
	if (n < 1) {
		return 0;
	}
	else {
		int r = 1;
		for (int i = n; i >= 1; i--) {
			r *= i;
		}
		return r;
	}
}

/**
* 交换两数组元素
*/

void swap(int* arr, int idx1, int idx2) {
	int temp = *(arr + idx1);
	*(arr + idx1) = *(arr + idx2);
	*(arr + idx2) = temp;
}

void addToRes(int* nums, int numsSize, int** res, int* returnSize) {
	int* arr = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		*(arr + i) = *(nums + i);
	}
	*(res + *returnSize) = arr;
	*returnSize = *returnSize + 1;
}

int isSwap(int* nums, int numsSize, int nth) {
	for (int i = nth + 1; i < numsSize; i++) {
		if (*(nums + nth) == *(nums + i)) {
			return 0;
		}
	}
	return 1;
}

/**
* 递归的计算有重复项数组的全排列
* @param nums 原数组
* @param numsSize 
* @param res 存放每次计算的结果,一个二维数组，
* @param returnSize res size的地址，初始化为 0
*/
void doPermuteUnique(int* nums, int numsSize, int** res, int* returnSize, int nth) {
	if (nth == numsSize) {
		addToRes(nums, numsSize, res, returnSize);
	}
	else {
		for (int i = nth; i < numsSize; i++) {
			if (isSwap(nums, numsSize, i)) {
				swap(nums, nth, i);
				doPermuteUnique(nums, numsSize, res, returnSize, nth + 1);
				swap(nums, nth, i);
			}
		}
	}
}

/**
* 使用递归的方法解决有重复项的数组的全排列
*/
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	// 对于有重复项的数组来说，最多也就 numsSize! 个
	int total = clcNFactory(numsSize);
	int size = 0;
	int** res = (int**)malloc(sizeof(int*) * total);
	doPermuteUnique(nums, numsSize, res, &size, 0);
	*returnSize = size;
	*(returnColumnSizes) = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		*(*(returnColumnSizes)+i) = numsSize;
	}
	return res;
}