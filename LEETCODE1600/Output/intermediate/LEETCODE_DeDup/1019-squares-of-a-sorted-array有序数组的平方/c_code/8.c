/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize){
	int *ret = (int*)malloc(ASize*sizeof(int));
	int* p1 = A, *p2 = NULL;
	int i = 0;
	while (p1 < A + ASize){//负数部分
		if (*p1 < 0){
			*p1 *= *p1;
			p1++;
		}
		else{
			p2 = p1;
			break;
		}
	}
    p1 = p1 - 1;
	while (p2&&p2 < A + ASize){//若p2为空则说明没有正数 防止访问空指针
		*p2 *= *p2;
		p2++;
	}
	p2 = p1 + 1;
	//归并排序
	while (p1 >= A&&p2 < A + ASize){
		if (*p1 < *p2){
			ret[i++] = *p1;
			p1--;
		}
		else{
			ret[i++] = *p2;
			p2++;
		}
	}
	//剩下的直接放进结果数组即可
	while (p1 >= A){
		ret[i++] = *p1;
		p1--;
	}
	while (p2&&p2 < A + ASize){
		ret[i++] = *p2;
		p2++;
	}
	*returnSize = ASize;
	return ret;
}