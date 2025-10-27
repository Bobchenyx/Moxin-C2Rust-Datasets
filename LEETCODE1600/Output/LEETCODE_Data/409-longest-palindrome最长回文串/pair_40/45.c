int longestPalindrome(char * s){
    int i = 0;
    int char_arr[128] = {0};
    int add_flag = 0;
    int count = 0;

    for (i = 0; s[i] != 0; i++){
        char_arr[s[i]]++;
    }

    if (i % 2 == 1) {
        add_flag = 1;
        for (i = 0; i < 128; i++) {
            count += char_arr[i] / 2 * 2;
        }
    } else {
        for (i = 0; i < 128; i++) {
            count += char_arr[i] / 2 * 2;
            if (char_arr[i] % 2 == 1) {
                add_flag = 1;
            }
        }
    }

    return count + add_flag;
}