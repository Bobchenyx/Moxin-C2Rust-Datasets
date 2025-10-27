typedef struct tagMap {
	int value;
	int pos;
} MAP_S;

int compare(const void* p1, const void* p2)
{
	return ((MAP_S*)p1)->value  - ((MAP_S*)p2)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int left;
	int right;
	int sum;
	int posLeft;
	int posRight;
	int* result = NULL;
	MAP_S* sortMaps = NULL;

	*returnSize = 0;
	if (nums == NULL || numsSize < 2) {
		return NULL;
	}
	sortMaps = (MAP_S *)malloc(numsSize * sizeof(MAP_S));
	for (int i = 0; i < numsSize; i++) {
		sortMaps[i].pos = i;
		sortMaps[i].value = nums[i];
	}

	qsort(sortMaps, numsSize, sizeof(MAP_S), compare);
	left = 0;
	right = numsSize - 1;

	while (left < right) {
		sum = sortMaps[left].value + sortMaps[right].value;
		if (sum < target) {
			left++;
		}
		else if (sum > target) {
			right--;
		} else {
			break;
		}
	}

	if (left != right) {
		result = (int *)malloc(2 * sizeof(int));
		posLeft = sortMaps[left].pos;
		posRight = sortMaps[right].pos;
		result[0] = posLeft > posRight ? posRight : posLeft;
		result[1] = posLeft > posRight ? posLeft : posRight;
        *returnSize = 2;
		free(sortMaps);
		return result;
	}
	free(sortMaps);
	return NULL;
}