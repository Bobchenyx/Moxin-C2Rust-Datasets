int minArray(int* numbers, int numbersSize){
    if(numbers[0] < numbers[numbersSize-1])
        return numbers[0];
    int i,low = 0,high = numbersSize-1,mid;
    while(low < high){
        mid = (low+high)/2;
        if(numbers[mid] < numbers[high]){
            high = mid;
        }
        else if(numbers[mid] > numbers[high]){
            low = mid+1;
        }
        else{
            high--;
        }
    }
    return numbers[low];
}