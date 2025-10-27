int hammingDistance(int x, int y){
    int yihuo = x ^ y;
    int count = 0;
    int test = 0;
    printf("yihuo = %d\n",yihuo);
    while(yihuo) {
        test = yihuo & 0x01;
        //printf("yihuo = %x ， test = %x\n",yihuo , test);
        if(test) {
            count++;
        }
        yihuo = yihuo >> 1;
    }
    return count;
}