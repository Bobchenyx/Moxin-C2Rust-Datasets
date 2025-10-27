void reverseString(char* s, int sSize){
    if(sSize==0||sSize==1) return ;
    unsigned int i,j,m;
    i=0;m=sSize/2;j=sSize-1;
    while(i<j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;j--;
    }
}