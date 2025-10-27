bool isPalindrome(int x){
if (x<0)
return false;
int n=x;
long m=0;
while(n>0){
    m *=10;
    m +=n%10;
    n /=10;  
}
return m==x;
}