char **list;
int cnt;
void proc(char *old, int len, char *add)
{
	if (*add == 0) {
		// printf("record: %s\n", old);
		list[cnt] = malloc(len + 1);
		strcpy(list[cnt++], old);
		return;
	}

	char *new = malloc(len + 2);//这里对内存耗费比较大，直接基于old添加和剔除新字符，应该也可以。
    for (int i = 0; i < len + 1; i++) {
		memcpy(new, old, i);
		new[i] = *add;
		memcpy(new + i + 1, old + i, len - i + 1);
		proc(new, len + 1, add + 1);
	}
    free(new);
}

char **permutation(char *S, int *returnSize)
{
	if (!S || !strlen(S))
		return *returnSize = 0;

	cnt = 0;
	list = malloc(8 * 370000);

	char t[10] = { S[0] };
	proc(t, 1, S + 1);
	*returnSize = cnt;
	return list;
}