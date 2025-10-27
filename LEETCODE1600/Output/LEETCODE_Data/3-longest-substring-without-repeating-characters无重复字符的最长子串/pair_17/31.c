int lengthOfLongestSubstring(char * s){
    if(*s=='\0') return 0;
    int len=1,maxlen=1;
    int i=0,j=0,t=i;
    while(s[j]!='\0'){
    	len=1;
    	t=i;
    	while(t<j&&s[t]!=s[j]){
    		len++;
    		t++;
		}
		if(maxlen<len)
			maxlen=len;
		if(t==j){
			j++;
		}
		else{
			i=t+1;
			j=j+1;
		}
    } 
    return maxlen;
}