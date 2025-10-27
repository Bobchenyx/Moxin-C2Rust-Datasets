char * longestPalindrome(char * s){
    int i=0, ii=0, length=0, maxlength=0;//length用来表示每次出现回文字符串的长度，maxlength表示最长情况
    int asc[128]={0},left[128]={0},cont[128]={0},where[2]={0};//asc记录是否出现过，left记录上次的位置，cont用来描述例如cccccccc这类特殊情况的，where用来记录最长回文字符串初末位置
    char *maxleg = (char*)malloc(1001*sizeof(char));//这里须注意，要malloc1001个char的空间
    while( s[i] != '\0' ){
    	if( asc[s[i]] ){
    		length = i - left[s[i]] + 1;//首先计算出相同字符的间隔长度（加上该字符）
    		if( s[i] == s[i-1] && s[i] == s[i+1] ){//这里是用来处理类如ccccc……连续字符特殊情况的
    			cont[s[i]] = 1;
    			for( ii=i+1; s[ii]==s[i]; ii++ ) length++;//这里是计算出连续字符串有多长
    			i = ii - 1;//使i跳转到最后一个重复字符出现的地方
			}
			if( length == 2 || length == 3 || cont[s[i]] != 0){//这里是判断回文字符串多长的地方
				for( ii=i+1; 1; ii++ ){
					int ii1 = ii - length - 1;
					if( ii1 >=0 ){//只有在ii1>=0的情况才运行
						if( s[ii] == s[ii1] ) length += 2;
						else break;
					}
					else break;
				}
				if( length > maxlength ){
					maxlength = length;
					where[0] = ii - maxlength;//用来记录最长回文字符串的首字符位置
					where[1] = ii - 1;//用来记录最长回文字符串的末字符位置
				}
			}
			cont[s[i]] = 0;
		}
		asc[s[i]] = 1;//每当有字符出现就将该字符记为1
		left[s[i]] = i;//上一次字符出现的位置记为当前i的位置
		i++;
	}
	ii = 0;
	if( where[0] == where[1] ) maxleg[ii++] = s[0];//用来处理无回文字符串的情况，只需要让maxleg随便等于一个字符
	else{
		for( i=where[0]; i<=where[1]; i++ ){
			maxleg[ii++] = s[i];
		}
	}
	maxleg[ii] = '\0';//需要注意的是这里，末尾必须为'\0'，否则出错
	return maxleg;
}