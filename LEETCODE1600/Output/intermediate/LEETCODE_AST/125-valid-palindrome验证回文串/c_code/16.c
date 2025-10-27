bool isPalindrome(char * s){
	int left = 0;
	int right = strlen(s) - 1;
	
	if( !s || right <= 0 ){
		return true;
	}
	
	char s_cpy[right+1];
	memcpy(s_cpy,s,strlen(s));
	
	while( left < right ){
		if( ( !isdigit(s_cpy[left]) ) && ( !isalpha(s_cpy[left]) ) ){
			++left;
			continue;
		}
		if( ( !isdigit(s_cpy[right]) ) && ( !isalpha(s_cpy[right]) ) ){
			--right;
			continue;
		}
		
		if( isupper(s_cpy[left]) ){
			s_cpy[left] = tolower(s_cpy[left]);
		}
		if( isupper(s_cpy[right]) ){
			s_cpy[right] = tolower(s_cpy[right]);
		}	
		
		if( s_cpy[left] == s_cpy[right] ){
			++left;
			--right;
			continue;
		}else{
			return false;
		}	
	}
	return true;
}
}