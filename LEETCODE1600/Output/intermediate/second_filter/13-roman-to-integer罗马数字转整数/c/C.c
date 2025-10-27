int romanToInt(char * s){
int i=1,v=5,x=10,l=50,c=100,d=500,m=1000;
int sum=0;
char *p=s;
char *next=NULL;
while(*p)
{
    next=p+1;
    if((*p=='I' && *next=='V')||(*p=='I' && *next=='X'))
        sum=sum-i;
    else if((*p=='X' && *next=='L')||(*p=='X' && *next=='C'))
        sum=sum-x;
    else if((*p=='C' && *next=='D')||(*p=='C' && *next=='M'))
        sum=sum-c;
    else
    {
        if(*p=='I')
            sum=sum+i;
        else if(*p=='V')
            sum=sum+v;
        else if(*p=='X')
            sum=sum+x;
        else if(*p=='L')
            sum=sum+l;
        else if(*p=='C')
            sum=sum+c;
        else if(*p=='D')
            sum=sum+d;
        else if(*p=='M')
            sum=sum+m;
    } 
    p++;
}
return sum;
}