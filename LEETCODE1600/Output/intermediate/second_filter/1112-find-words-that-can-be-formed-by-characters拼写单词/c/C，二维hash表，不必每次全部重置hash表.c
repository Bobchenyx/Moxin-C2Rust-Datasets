int countCharacters(char ** words, int wordsSize, char * chars){
   int i,j,k,check,result=0,hash[26]={0},whash[2][26]={0};
   for(i=0;chars[i]!='\0';i++){
       j=(int)(chars[i]-'a');
       hash[j]++;
   }
   for(i=0;i<wordsSize;i++){
       check=1;
       for(j=0;words[i][j]!='\0';j++){
           k=(int)(words[i][j]-'a');
           if(whash[1][k]!=i){
               whash[0][k]=1;
               whash[1][k]=i;
           }else whash[0][k]++;
           if(hash[k]<whash[0][k]){
               check=0;
               break;
           }
       }
       if(check==1) result+=j;
   }
   return result;
}