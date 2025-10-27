bool hasGroupsSizeX(int* deck, int deckSize){
    if(deckSize==1) return false;
    int gcd(int x,int y);
    int hash[10000];
    int i;
    memset(hash,0,sizeof(hash));
    //模拟了哈希表
    for(i=0;i<deckSize;i++) hash[deck[i]]++;
    int X=hash[0];
    for(i=0;i<10000;i++){
        if(hash[i]==1) return false;
        //X记录数组deck中所有数字出现次数的gcd
        X=gcd(X,hash[i]);
        if(X==1) return false;
    }
    return true;
}
//的确不用判断x与y的大小关系
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}