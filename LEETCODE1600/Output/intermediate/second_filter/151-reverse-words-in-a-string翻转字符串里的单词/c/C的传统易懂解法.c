char * reverseWords(char * s) {
	int len = strlen(s);
	char *res = (char *)malloc(sizeof(char)*(len + 10)); //返回字符串
	memset(res, 0, sizeof(char)*(len + 10));
	int res_len = 0;
    int flag=0;
	for (int i = len - 1; i >= 0; i--) {
		int right=0, left=0; //确定一个单词的首尾index
		if (s[i] != ' ') {
            flag=1;
			right = i;
			for (int j = i; j > 0; j--) {
				if (s[j - 1] == ' ') {
					left = j;
					break;
				}
			}
            if(left<=right){
                for (int t = left; t <= right; t++) {
                    res[res_len++] = s[t];
                }
            }
			res[res_len++] = ' ';
			i = left;
		}
	}
//要注意如果s为空字符串，那么要返回“”，用flag来标记s是否为空字符串
    if(flag==0)
        return "";
	res[res_len-1] = '\0';
//在for循环中在每次输入完一个单词后还要添加一个空格，这里的作用是取消最后一个
//单词后面的空格
    
	return res;
}