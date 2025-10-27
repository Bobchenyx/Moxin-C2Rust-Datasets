char * reverseWords(char * s){
    int i,m,n,j,g,pre=0,blank=0,num=0;
    char temp;
   
   for(i=0;s[i]!='\0';i++)
   { 
       if(s[i]==' ')                                          
       {   if(pre==0||s[i+1]==' '||s[i+1]=='\0')  //无用空格        
             blank++;
           else                                              
              s[i-blank]=s[i];                   //有用空格
      
       }
       else                                                                
        {   pre=1;  
             if(s[i+1]==' '||s[i+1]=='\0')        //单词最后一个字母
            {   
                num++;
                s[i-blank]=s[i];
                for(m=i-blank-num+1,n=i-blank;m<n;m++,n--) 
             {
                temp=s[m];
                s[m]=s[n];
                s[n]=temp; 
             }
             num=0;
            }          
            else                                 //中间字母
            {                                        
              num++;
              s[i-blank]=s[i];
              }
           }   
     }         

     s[i-blank]='\0';

     for(j=0,g=i-blank-1;j<g;j++,g--)                    
     {    temp=s[j];
          s[j]=s[g];
          s[g]=temp; 
}

return s;
}