static int FindKthNumber(int *A, int Asize, int *B, int Bsize, int K)
{
	int number = 0;
	int k = K;
	int stride = 0; // 查找步进，以便应付特殊情况
	int i = 0, j = 0;
	while (k > 1)
	{
		int oi = i, oj = j; // 记录初始i、j，以便每轮结束时将被放弃的数组下标重置
		int kA = 1, kB = 1; // i和j当前所指数字各算一个
		if ((Asize - i) != 0 && (Bsize - j) != 0) //计算步长
		{
			stride = (Asize - i) <= (Bsize - j) ? (Asize - i) : (Bsize - j);
			stride = (k / 2 <= stride) ? (k / 2) : stride;
		}
		else
		{
			stride = (k / 2 <= (Asize - i + Bsize - j)) ? k / 2 : (Asize - i + Bsize - j);
		}
		while (i < Asize && kA < stride)
		{
			i++;
			kA++;
		}
		while (j < Bsize && kB < stride)
		{
			j++;
			kB++;
		}
		// 去掉找到的数字，并更新所在数组的下标
		k = k - stride;
		if (j < Bsize && i < Asize) // 如果两个数组都还没遍历完，则通过比较第k/2小数决定更新哪个数组的下标
		{ 
			if (A[i] <= B[j])
			{
				i++;
				j = oj;
			}
			else
			{
				j++;
				i = oi;
			}
		}
		else if(j == Bsize) // 数组B已遍历完，当前下标要有效，只能是在数组A中
		{
			i++;
			j = oj;
		}
		else // i == Asize
		{
			j++;
			i = oi;
		}
	}

	// 判断第k小数在哪个数组，如果A、B均未遍历完则通过比较当前下标确定，如果任一数组遍历完则在未遍历完数组当前下标
	if (i < Asize && j < Bsize)
	{
		number = A[i] <= B[j] ? A[i]: B[j];
	}
	else if(j == Bsize)
	{
		number = A[i];
	}
	else // i == Asize
	{
		number = B[j];
	}
	
	return number;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if (nums1 == NULL || nums2 == NULL || (nums1Size == 0 && nums2Size == 0))
	{
		return -1;
	}
	double n = 0, m = 0;
	if ((nums1Size + nums2Size) % 2 == 1) // 奇数
	{
		n = FindKthNumber(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 + 1);
		return n;
	}
	else // 偶数
	{
		n = FindKthNumber(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2);
		m = FindKthNumber(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 + 1);
		return (n + m) / 2.0;
	}
}