bool isPalindrome(int x){
long trans=0;
int x_x=x;

if(x<0 )
    return false;
if(x%10 == 0 && x > 10)
        return false;

while(x)
{
    
    trans=trans*10+x%10;
    x=x/10;
}
if(x_x==trans)
{
    return true;
}
else
    return false;
}