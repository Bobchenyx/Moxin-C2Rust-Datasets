#define RES_LEN 5000


char * countAndSay(int n)
{	
	char *str = (char *)malloc(RES_LEN*sizeof(char));
	char *tmp = (char *)malloc(RES_LEN*sizeof(char));
	str[0]='1';
	str[1]='\0';
	
	
	int i, j, count;
	char key;
	char *p;
	
	for(i = 1; i < n; i++){
		j = 0;
		key = str[0];
		count = 0;
		p = str;
		while(*p != '\0'){
			
			if(*p == key){
				count++;
			}else{
				tmp[j++] = count + '0';
				tmp[j++] = key;
				count = 1;
				key = *p;
			}
			p++;
		}
		tmp[j++] = count + '0';
		tmp[j++] = key;
		tmp[j] = '\0';
		strcpy(str, tmp);
	}
	return str;
}