bool isUnique(char* astr){
	char test[128] = {0};
	int len = strlen(astr);
	for (int i = 0; i < len; i++) {
		test[astr[i]]++;
		if(test[astr[i]] >1) {
			printf("false\r\n");
			return false;
		}
	}
	printf("true\r\n");
	return true; 	
	
}