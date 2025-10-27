bool isPalindrome(int x){
    long count=0;
    int pre=x;
    if(x<0){
        return false;
    }
    else if(x==0){
        return true;
    }
    else{
        while(x!=0){
            count=count*10+x%10;
            x=x/10;
        }
        if(count==pre){
            return true;
        }
        else{
            return false;
        }
    }
}