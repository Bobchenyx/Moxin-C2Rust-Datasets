bool isValid(char * s){
    int i,count=0;  
    int len = strlen(s);
    //处理空字符串。
    if(len==0) return true;    
    char *ptr = (char *)malloc(sizeof(char)*(len+1));  
    memset(ptr,0,len+1);
    for(i=0;i<len;i++)
    {
        if((s[i]=='(')||(s[i]=='{')||(s[i]=='[')){
            count++;
            ptr[count]=s[i];
            
        }
        else if((s[i]==ptr[count]+1)||(s[i]==ptr[count]+2)){
            count--;
        }      
        else  return false;   
    }
    free(ptr);
    
    if(count) return false;
    return true;
}