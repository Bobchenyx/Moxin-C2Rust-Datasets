bool isPalindrome(int x){
 if(x<0) return false;
 else if(!x) return true;
 int x1=x;int len=0;
 int num=0;int ten=1;
 while(x1!=0){
   len++;
   x1/=10;
 }
 x1=x;
 for(int i=0;i<len/2;i++){
   num=num*10+x1%10;
   x1/=10;
   ten*=10;
 }
  if(len%2==1) ten*=10;
  if(x/ten==num)
  return true;
  return false;
}