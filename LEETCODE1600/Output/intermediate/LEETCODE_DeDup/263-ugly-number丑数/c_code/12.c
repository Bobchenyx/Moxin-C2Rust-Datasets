bool isUgly(int num){
    int t[3]={2,3,5};
    int flag=1;
    int i=0;
    while(num && flag){
        if(num%t[i]==0){
            num=num/t[i];
        }
        else{
            if(i==2){
                flag=0;
            }
            else{
                i++;
            }
        }
    }
    if(num!=1)
        return false;
    return true;

}