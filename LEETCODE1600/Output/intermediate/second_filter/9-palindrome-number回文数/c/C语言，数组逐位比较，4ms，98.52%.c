bool isPalindrome(int x){
    if (x < 0) return false;

    if (x < 10) return true;

    int numbers[10];
    int index = 0;
    int src = x;
    while (src) {
        numbers[index] = src % 10;
        src /= 10;
        index++;
    }

    int i = 0, j = index - 1;

    while( i < j) {
        if (numbers[i] != numbers[j]) return false;
        i++;
        j--;
    }
    
    return true;
}