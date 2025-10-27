#define MAX_SIZE 26
char * longestCommonPrefix(char ** strs, int strsSize){
    
     char *a = (char *)malloc(sizeof(char *) * MAX_SIZE);
     a[0]='\0';
     int i,j,len;
     char temp;
     if(strsSize==0){return a;}
     len=strlen(strs[0]);
     for(i=0;i<len;i++){
         for(j=0;j<strsSize;j++){
             temp=strs[0][i];
             if(temp!=strs[j][i]){
                 a[i]='\0';
                 return a;
             }
        a[i]=temp;
        a[i+1]='\0';

         }
     }
     return a;

}