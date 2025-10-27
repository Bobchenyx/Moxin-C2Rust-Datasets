int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize=2;
    int *result = (int*)malloc(sizeof(int)*2);
    double mid = (double)target / 2.0;
    int sum = 0;
    int i = 0;
    int* front =NULL;
    int* back = NULL;

    //寻找target中值位置
    for(i = 0; i < numbersSize; ++i){
        if((double)numbers[i]> mid) break;
        else if ((double)numbers[i]==mid) {
            ++i;
            break;
        }
    }
        
    //两个指针，分别两边扩散
    front = numbers + i - 1;   
    back = numbers + i;
    while(true){
        sum = *front+*back;
        if(sum == target) break;
        else if (sum>target) front--;
        else back++;
    }
    result[0] = front - numbers + 1;
    result[1] = back - numbers + 1;

    return result;
}