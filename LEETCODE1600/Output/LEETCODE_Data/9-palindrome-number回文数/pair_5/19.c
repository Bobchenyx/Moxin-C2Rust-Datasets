int ary[10000];

bool isPalindrome(int x){
    int index = 0;
    int left = 0;
    int right = 0;
    int y =0;

    if (x < 0) {
        return false;
    }

    if (x < 10) {
        return true;
    }

    do {
        y = x % 10;
        x = x / 10; 
        ary[index] = y;
        index ++;
    } while(x != 0);

    right = index - 1;
    for(;left ++, right --; left >= right) {
        if (ary[left] != ary[right]) {
            return false;
        }
    }
    return true;
}