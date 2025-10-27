char * longestCommonPrefix(char ** strs, int strsSize)
{
	if (strsSize == 0){
		return "";
	}
	int i = 0;
	int j;
	char *res = (char *)malloc(sizeof(char) * 1000);
	memset(res, 0, 1000);
	int flag = 0;
	while(strs[0][i] != '\0'){
		for(j = 1; j < strsSize; j++){
			if(strlen(strs[j])==0){
				return "";
			}
    		    
			if(strs[j][i]=='\0' || strs[0][i] != strs[j][i] ){				
				flag = 1;
			}
		}
		if(flag == 0){
			*(res+i) = strs[0][i];
		}else{
			break;
		}
		i++;
	} 
	
	return res;
}