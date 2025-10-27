char * intToRoman(int num){
    int i=0,a[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
	char *final=NULL;
	final=(char*)malloc(16);
	memset(final, 0, 16);
	char *romaji[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	while(num>0)
	{
		if(num/a[i]>=1)
		{
			num=num-a[i];
			strcat(final,romaji[i]);
		}
		else{
			i++;
		}
	}
	return final;

}