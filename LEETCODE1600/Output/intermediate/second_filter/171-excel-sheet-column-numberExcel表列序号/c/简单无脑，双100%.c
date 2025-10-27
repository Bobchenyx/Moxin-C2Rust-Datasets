int titleToNumber(char * s){
int a=0;
int i=0;
int sum=0;
for(;s[i]!='\0';i++)
{
 a=s[i]-'A'+1;
sum=sum*26+a;
}
return sum;
}