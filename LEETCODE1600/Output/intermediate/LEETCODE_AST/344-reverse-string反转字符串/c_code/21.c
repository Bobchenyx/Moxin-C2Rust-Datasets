void reverseString(char* s, int sSize){
    for (int a = 0, b = sSize-1; a < b; a++, b--){
        s[a] = s[a] ^ s[b];
        s[b] = s[a] ^ s[b];
        s[a] = s[a] ^ s[b];
    }
}