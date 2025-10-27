int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

bool hasGroupsSizeX(int* deck, int deckSize){
    bool res=false;
    int i, X, num;

    qsort(deck, deckSize, sizeof(int), cmpfunc);  // 数组从小到大排序
    for(X=1; X<deckSize; X++){  //X:分组的组数
        if(deckSize%X==0){
            num = deckSize/X;  // 每组元素个数
            for(i=0; i<deckSize; i+=num){
                if(deck[i]==deck[i+num-1]){  // 因为已经排好序了，只需要判断每组的首尾元素是否相同
                    res = true;
                }else{
                    res = false;
                    break;
                }
            }
            if(res){
                return res;
            }
        }
    }
    return false;
}