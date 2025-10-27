char * minWindow(char * s, char * t){
	int window[128];
	int need[128];
	int len_need = 0;
	int min_len = INT_MAX;
	int start=0;
	int left=0,right=0;
	int match=0;
	
	int len_s = strlen(s);
	int len_t = strlen(t);
	
	memset(window, 0, sizeof(int)*128);
	memset(need, 0, sizeof(int)*128);
	
	int i;
	for(i=0;i<len_t;i++){
		if(need[t[i]]==0){
			len_need+=1;
		}
		need[t[i]]++;
	}
	
	while(right<len_s){
		char s1 = s[right];
		if(need[s1]){
			window[s1]++;
			if(window[s1]==need[s1]){
				match++;
			}
		}
		right++;
		
		while(match==len_need){
			if (min_len>(right-left)){
				start = left;
				min_len = right - left;
				
			}
			
			char s2 = s[left];
			if(need[s2]){
				window[s2]--;
				if (window[s2]<need[s2])
					match--;
				
			}
			left++;
		}
	}
	if(min_len==INT_MAX){
		return "";
	}	
	else{
		s[start+min_len]='\0';
		return s+start;
	}	
}