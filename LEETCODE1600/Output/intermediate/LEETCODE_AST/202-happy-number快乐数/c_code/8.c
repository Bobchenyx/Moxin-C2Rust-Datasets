bool isHappy(int n){
    int lj,t,cnt=0;
    while(1){
        lj=0;
        cnt++;
        while(n){
            t=n%10;
            lj+=t*t;
            n/=10;
        }
        if(lj==1) return true;
        n=lj;
        if(cnt>50) break;
    }
    return false;
}