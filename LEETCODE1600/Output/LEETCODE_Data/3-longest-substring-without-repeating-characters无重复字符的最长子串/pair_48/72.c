int lengthOfLongestSubstring(char * s){
    int i,j,k=0;
	int p;//标识符，可以理解为flag
	int l[100000]={1};
	int o;//l[]数组的下标
	k=0;o=0;//初始化
    if(strlen(s)==0) return 0;//处理空字符串的情况
	for(i=1;i<strlen(s);i++){//遍历整个字符串
		p=1;
		for(j=k;j<i;j++){//遍历已遍历的字符块，查看是否存在相同的字符；l记录的就是该字符块的长度
			if(s[i]==s[j]){
				p=0;break;//如果有相同字符，退出循环。
			}
				
		}
		if(p==1){//没有相同字符的情况下，直接l++，并设置下一次已遍历字符块 遍历开始的位置
			k=i-l[o];
			l[o]++;
		}
		else{//将k设置为已遍历字符块中重复字符的下一个位置，重置长度为i-j；放弃重复字符之前的字符块
            l[++o]=i-j;
			k=j+1;
			
		}
	}
	int max=l[0];//从众多的l中挑选出最大的那一个。
	for(i=0;i<=o;i++)
		if(l[i]>max){
			max=l[i];
		}
	printf("%d",max);			
    return max;
}