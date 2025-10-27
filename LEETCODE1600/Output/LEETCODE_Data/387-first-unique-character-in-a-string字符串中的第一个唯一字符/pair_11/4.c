int firstUniqChar(char * s){
     int i,j;
     int l=strlen(s);
     char a[26];
     int  b[26]={0};
     if(l == 0)
      return -1;
     for(i=0;i<26;i++){
         a[i]='a'+i;
     }
    
     for(i=0;i<l;i++){
         for(j=0;j<26;j++){
           if(a[j]==s[i]){
                b[j]+=1;
           }
         }
     }
     for(j=0;j<l;j++){
         if(b[s[j]-'a']==1){
             return j;
         }
     }
     return -1;
}