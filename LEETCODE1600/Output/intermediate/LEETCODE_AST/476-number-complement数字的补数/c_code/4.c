int findComplement(int num){

    int res = 0;
    int cnt = 0;
    int j = 0;
    while ( num != 0){
       cnt =  num & 0x1;
       res = res +  (1-cnt) * pow(2, j++);
       num >>= 1;
    }
    return res;
}