bool canThreePartsEqualSum(int* A, int ASize){
    int Total = 0;
    int Left = 0;
    int first = 0;

    if(ASize < 3){
        return 0;
    }
    //计算总值
    for(int i = 0; i < ASize;i++){
        Total = Total+A[i];
    }
    //找第一个数组
    for(int j = 0; j < ASize;j++){
        Left += A[j];
        Total -= A[j];
        if(Left*2 == Total && !first){
            first = 1;
            Left = 0;
        }else if(Left == Total && first && j != ASize-1){
            return 1;
        }
    }
    return 0;
}