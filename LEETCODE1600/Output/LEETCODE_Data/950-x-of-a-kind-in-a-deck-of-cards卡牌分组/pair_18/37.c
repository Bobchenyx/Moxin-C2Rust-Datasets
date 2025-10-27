bool hasGroupsSizeX(int* deck, int deckSize){
    int nums[100000]={0};
    for(int i=0;i<deckSize;i++){
        nums[deck[i]]++;//用来记录数字出现的次数
    }
    int p=1;//标识符，可以理解为flag
    for(int j=2;j<=100;j++){//寻找约数
        p=1;
        for(int i=0;i<deckSize;i++){
            if(nums[deck[i]]%j!=0){//不能整除，则退出第二个循环，并对p进行判断
                p=0;
                break;
            }
        }
        if(p==1) break;//找到能整除的约数 退出循环
        else continue;//否则，进入下一次循环
    }
    if(p==0){
        return false;
    }
    else return true;
}