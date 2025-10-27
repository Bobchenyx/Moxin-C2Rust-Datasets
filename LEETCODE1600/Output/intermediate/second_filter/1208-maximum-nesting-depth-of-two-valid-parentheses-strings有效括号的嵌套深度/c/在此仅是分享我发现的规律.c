#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* maxDepthAfterSplit(char* seq, int* returnSize) {
	int k = 0, j = 0, n = 1, a = strlen(seq), x = 0, r1 = 0, r2 = 0, cnt1 = 0, cnt2 = 0;
	int *q;q=(int*)malloc(sizeof(int)*a);
	for ( j= 0; j < a; j++)
		q[j] = -1;
	while (x != a)
	{
		k = a - 1; j = 0; n++; x = 0; r1 = r2 = 0;
		while (k >= 0)
		{
			if (q[k] == -1 || q[k] == -2)r1 = 1;
			else r1 = 0;
			if (q[j] == -1 || q[j] == -2)r2 = 1;
			else r2 = 0;
			if (r1 == 1) {
				if (seq[k] == ')')cnt1++;
				else
					cnt1--;
				if (cnt1 == 0)q[k]--;
			}
			if (r2 == 1)
			{
				if (seq[j] == '(')cnt2++;
				else cnt2--;
				if (cnt2 == 0)q[j]--;
			}
			k--; j++;
		}
		for (int p = 0; p < a; p++)
		{
			if (q[p] == -2)q[p] = n % 2;//???
			if (q[p] != -1)x++;
		}
	}
    *returnSize=a;
	return q;
}