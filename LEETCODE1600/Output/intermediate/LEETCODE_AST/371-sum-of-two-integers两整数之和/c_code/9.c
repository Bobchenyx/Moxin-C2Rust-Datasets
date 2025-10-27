int getSum(int a, int b){
    if(a>0){
        while(a--) b++;
    }else{
        while(a++!=0) b--;
    }
     return b;

}