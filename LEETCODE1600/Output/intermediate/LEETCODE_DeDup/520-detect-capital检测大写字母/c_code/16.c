c []
#define isupper(ch) (ch < 97 ? 1 : 0)

bool detectCapitalUse(char * word){
    bool first = isupper(*word++), second;
    if (*word) second = isupper(*word++);
    else return true;
    if (!first && second) return false;      // 小大
    while (*word) {
        first = isupper(*word++);
        if (first != second) return false;
    }
    return true;
}