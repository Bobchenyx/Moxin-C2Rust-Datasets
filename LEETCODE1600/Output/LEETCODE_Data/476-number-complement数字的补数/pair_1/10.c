int findComplement(int num){
    if(num < 2){
        return !num;
    }else{
        return findComplement(num / 2) * 2 + !(num % 2);
    }
}