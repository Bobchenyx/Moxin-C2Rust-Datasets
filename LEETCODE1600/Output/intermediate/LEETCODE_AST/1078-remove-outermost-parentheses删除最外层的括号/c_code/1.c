char * removeOuterParentheses(char * S){

    char *q=S;
    char *x=malloc(sizeof(char)*1024*5);
    char *z=x;
    char *p=NULL;
    int r=0,l=0,num;
    while(*q!='\0')
    {   
        if(*q=='(')
        {
            l++;
        }else
        {
            r++;
        }
        if(l==r)
        {
            num=l+r-2;
            p=q-num;
            while(p!=q)
            {
                *z=*p;
                z++;
                p++;    
            }
            l=0;
            r=0;
        }
        *q++;
    }
    *z='\0';
    return x;
}