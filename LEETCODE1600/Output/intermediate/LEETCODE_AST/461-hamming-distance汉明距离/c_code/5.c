int hammingDistance(int x, int y){
    int tmp;
    int num = 0;

    tmp = x^y;
    if(tmp==0){
        return 0;
    }

    while(tmp){
        if(tmp%2 == 1){
            num++;
        }
        tmp=tmp/2;
    }

    return num;
}