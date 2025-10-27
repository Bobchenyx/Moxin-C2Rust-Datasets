bool canPermutePalindrome(char* s){
    int a[128]={0};
    while(*s!=0){
        a[*s]++;
        s++;
    }
    int i=0,sum=0;
    while(i<128){
        if(a[i]%2!=0){
            if(sum>0){
                return false;
            }
            sum++;
        }
        i++;
    }
    return true;
}