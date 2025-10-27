int findComplement(int num){
    int res=0,temp=0,c=0;
    while(num){
        temp=temp<<1;
        temp=temp+!(num%2); //从低到高，每位取反。如1000-->1110
        num/=2;
        c++;                //保存二进制中不含前导零的位数
    }
    
    for(int i=0;i<c;i++){   //颠倒二进制。如1110-->0111
        res=res<<1;
        res=res+(temp&1);
        temp=temp>>1;
    }
    return res;
}