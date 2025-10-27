char * countAndSay(int n){
    char mstr[8000] = "1",nstr[8000] = "\0",*pm,*pn;
    
    while(--n){
    	pm = mstr;
		pn = nstr;
    	char ch = mstr[0];
		int count = 1; 
		do{
			pm++;
		    if(*pm == ch) count++;
			else{
				*pn++ = count+'0';
				*pn++ = ch;
				ch = *pm;
				count = 1;
			}
		}while(*pm != '\0');
        
		*pn = '\0';
		strcpy(mstr,nstr);
	}
    pm = mstr;
    return pm;
}