bool isPalindrome(int x){
    if(x<0) return false;
    int a[1024]={0},flag=1,i=0,j=0;
    while(x>0){
        a[i]=x%10;
        i++;
        x/=10;
    }
    for(;j<i;j++){
        if(a[j]!=a[i-1-j]){
            flag=0;
        }
    }
    return flag?true:false;
}