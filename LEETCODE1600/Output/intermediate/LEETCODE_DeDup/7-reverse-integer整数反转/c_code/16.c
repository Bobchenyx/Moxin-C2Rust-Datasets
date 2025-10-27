int reverse(int x){
  int flag=0;
  if(x<0) flag=1;
  if(x==-2147483648) return 0;
  x=abs(x);
  long long a=0;
  while(x!=0){
      if(a*10>2147483647) return 0;
      a*=10;
      if(a+x%10>2147483647) return 0;
      a+=x%10;
      x/=10;
  } 
  if(flag)
  return -a;
  else return a;
}