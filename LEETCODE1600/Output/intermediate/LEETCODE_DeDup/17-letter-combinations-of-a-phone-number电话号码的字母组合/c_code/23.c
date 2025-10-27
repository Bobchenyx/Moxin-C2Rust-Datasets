char ** letterCombinations(char * digits, int* returnSize){
    
    *returnSize = 0;
	if (strlen(digits) == 0)
		return NULL;

	char *map[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	int length = strlen(digits);

	int *digits_num = (int *)malloc(sizeof(int) * (length + 1));
	int digits_sum = 1;
	digits_num[0] = 1;
	for (int i = (length - 1), j = 1; i >= 0; i--)
	{
		if (digits[i] == '2' || digits[i] == '3' || digits[i] == '4' ||
			digits[i] == '5' || digits[i] == '6' || digits[i] == '8')
			digits_sum *= 3;
		if (digits[i] == '7' || digits[i] == '9')
			digits_sum *= 4;
		digits_num[j++] = digits_sum;
	}
	*returnSize = digits_sum;

	char **ret = (char **)malloc(sizeof(char *) * digits_sum);
	for (int i = 0; i < digits_sum; i++)
		ret[i] = (char *)malloc(sizeof(char) * (length + 1));
    
	for (int i = 0; i < length; i++)
	{
		int index = 0;
		for (int k = 0, j = 0; k < (digits_num[length] / digits_num[length - i]); k++) //循环
		{
			int n = 0;
			for (; n < (digits_num[length - i] / digits_num[length - 1 - i]); n++) //当前层有多少个字母
			{
				for (; j < ((n + 1) * (digits_num[length - 1 - i]) + index * (digits_num[length - 1 - i]) * (digits_num[length - i] / digits_num[length - 1 - i])); j++) //重复
				{
					ret[j][i] = map[digits[i] - '2'][n];
                    //printf("ret[%d][%d] = %c\t", j, i, ret[j][i]);
				}				
			}
			index++;
		}
	}
    for (int i = 0; i < digits_sum; i++)
    {
		ret[i][length] = '\0';
    }
    
    free(digits_num);
    return ret;
}