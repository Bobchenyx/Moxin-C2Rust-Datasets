int cmp(const int *a, const int *b)
{
	return *a > *b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
	int gi = 0;
	int si = 0;
	int cnt = 0;
	qsort(g, gSize, sizeof(int), cmp);
	qsort(s, sSize, sizeof(int), cmp);
	while (si < sSize && gi < gSize) {
		if (g[gi] <= s[si]) {
			cnt++;
			gi++;
			si++;
		} else {
			si++;
		}
	}
	return cnt;
}