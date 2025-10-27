#include<stdio.h>
#include<math.h>
char* compressString(char* S){
int i;int count=1;
int len=strlen(S);
char *str=(char *)malloc(sizeof(char)*2*len);
str[0]=S[0];
int k=1;
int a[5];
int b=0;
if(len<=2)
{return S;}
for(i=0;i<len;i++)
{
if(S[i]==S[i+1])
{
    count++;
}
else {
    if(count>=10)
    {  while(count!=0)
    {
        a[b]=count%10;
        count=count/10;
        b++;
    }
    while(b>0)
{str[k]=a[--b]+'0';
k++;}
str[k]=S[i+1];
k++;
        count=1;
    }
else {
str[k]=count+'0';
k++;
str[k]=S[i+1];
k++;
count=1;
}
}
}
if(k-2<len)
return str;
else return S;
}