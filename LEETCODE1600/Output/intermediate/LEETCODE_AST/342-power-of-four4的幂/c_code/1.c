bool isPowerOfFour(int num){
    double res=log10(num)/log10(4);
    return (int)res-res==0;
}

bool isPowerOfFour(int num){
    if(num<=0) return 0;
    if(num==1) return 1;
    while(num!=0){
        if(num%4!=0) return 0;
        num=num/4;
        if(num==1) return 1;
    }
    return 0;
}

bool isPowerOfFour(int num){
    if(num<=0) return 0;
    if(num==1) return 1;
    return(num%4==0)&&isPowerOfFour(num/4); 
}