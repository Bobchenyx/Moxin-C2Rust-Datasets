int maximum69Number (int num){
    int i=0;
    int ad;
    int base=num;
    int maxx;
    while(num>0){
        i++; 
        if (i==1){
            ad=1;
        }else {
            ad=ad*10;
        }       
        if (num%10 < 9){
            maxx=ad;
        }
        num /=10;
    }    
    return base+3*maxx;
    
}