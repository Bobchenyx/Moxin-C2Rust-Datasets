char * countAndSay(int n)
{  int i,j,k,m,num;
   char p,q;
   char *res1=(char *)malloc(sizeof(char)*5000);
   char *res2=(char *)malloc(sizeof(char)*5000);
   char *temp;
   res1[0]=1+'0';
   if(n==1)
   { res1[1]='\0';
     return res1;
   }
   k=1;
   for(i=2;i<=n;i++)
   {  m=k;
      k=0;
      for(j=0;j<m;)
      { num=1;
        p=res1[j];
        j++;
        while(res1[j]==p)
        {  num++;
           j++;
        }
        res2[k]=num+'0';
        k++;
        res2[k]=p;
        k++;
      }
      temp=res1;
      res1=res2;
      res2=temp;
    }
    res1[k]='\0';
    free(res2);
    return res1;
}