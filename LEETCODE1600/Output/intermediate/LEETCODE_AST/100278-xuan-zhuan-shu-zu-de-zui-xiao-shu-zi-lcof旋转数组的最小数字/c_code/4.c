int minArray(int* numbers, int numbersSize){
    int ans = numbers[0];
    for (int i = 1; i < numbersSize; ++i) {
        if (numbers[i] < numbers[i - 1]) {
            ans = numbers[i];
            break;
        }
    }
    return ans;
}