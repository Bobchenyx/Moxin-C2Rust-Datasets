char *num_2_char[8] = {
    { "abc" },
    { "def" },
    { "ghi" },
    { "jkl" },
    { "mno" },
    { "pqrs"},
    { "tuv" },
    { "wxyz"} 
};
char num_2_char_size[] = { 3,3,3,3,3,4,3,4 };
char ** letterCombinations(char * digits, int* returnSize) {

	int dig_len = strlen(digits);
	if(dig_len == 0){
		*returnSize = 0;
		return NULL;
	}
	char* result, *c_ptr;
	char** ans;
	int i, k, pos = 0;
	char index = 0, *counter;
	k = 1;
	for (i = 0; i < dig_len; i++) {
		k *= num_2_char_size[digits[i] - '2'];
	}
	result = (char*)malloc(k * (dig_len + 1));
	counter = (char*)malloc(dig_len);
	ans = (char**)malloc(k * sizeof(char*));
	memset(counter, 0, dig_len);

	c_ptr = result;
	index = 0;
	while (index < dig_len) {
		for (i = 0; i < dig_len; i++) {
			c_ptr[i] = num_2_char[digits[i] - '2'][counter[i]];
		}
		c_ptr[i] = '\0';
		ans[pos++] = c_ptr;
		c_ptr += dig_len + 1;
		index = 0;
		//做加法运算，超过num_2_char_size[]后进位
		while ((index < dig_len) && ((++counter[index])>= num_2_char_size[digits[index] - '2'])) {
			counter[index] = 0;
			index++;
		}
	}

	*returnSize = pos;
	return ans;
}