int lengthOfLongestSubstring(char * s){
    if (s[0]=='\0')
		return 0;
	if (s[1]=='\0')
		return 1;
	
	int max = 0;
	int begin = 0;
	int end;
	bool flag;//判断当前字符是否在画出的窗口内
	int k;
	
	for(end=1;s[end]!='\0';end++){
		flag = false;
		for(k=begin;k<end;k++){
			if(s[k]==s[end]){
				flag = true;
				max = (max>(end-begin))?max:end-begin;
				begin = k+1;
				break;
			}
		}
		
		if(!flag){
			max = max>(end-begin+1)?max:(end-begin+1);
		}
	}
	
	return max;
}