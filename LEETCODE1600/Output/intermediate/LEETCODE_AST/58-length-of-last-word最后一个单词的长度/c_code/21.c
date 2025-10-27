int lengthOfLastWord(char * s){
  int i,len=strlen(s);
  int num=0,flag=0;
  for(i=len-1;i>=0;i--)
  {
      if(s[i]!=' ')
       {
           num++;
           flag=1;
       }
      else
      {
          if(flag==1)
          return num ;
      } 
  }
  return num ;
}