int romanToInt(char * s){
   int len=strlen(s);
   int sum=0;
   int a[200];
   for(int i=0;i<200;i++)a[i]=0;
   a['I']=1;
   a['V']=5;
   a['X']=10;
   a['L']=50;
   a['C']=100;
   a['D']=500;
   a['M']=1000;
   a['I'+'V']=4;
   a['I'+'X']=9;
   a['X'+'L']=40;
   a['X'+'C']=90;
   a['C'+'D']=400;
   a['C'+'M']=900;
    for(int i=len-1;i>=0;i--){
       if(i-1>=0&&a[s[i]]>a[s[i-1]]&&a[s[i]+s[i-1]]!=0) {
         sum+=a[s[i]+s[i-1]];
         i--;
       }
       else sum+=a[s[i]];
   }
return sum;
}