bool isValid(char * s){
    int low = -1, high = 0;

    while (s[high] != '\0') {
        if (s[high] == '(' || s[high] == '[' || s[high] == '{') {
            s[++low] = s[high++];
        } else if (low >= 0
                    && (s[high] - 1 == s[low] || s[high] - 2 == s[low])) {
            --low;
            ++high;
        } else {
            return false;
        }
    }

    return low == -1;
}