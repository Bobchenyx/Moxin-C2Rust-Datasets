char * predictPartyVictory(char * senate){
    bool R = true;
    bool D = true;
    int flag = 0;
    int qLen = strlen(senate);
    int i;
    char *p = senate;
    // 遍历数组直到出现一方一个不剩
    while (R & D) {
        R = false;
        D = false;
        // 遍历剩余数组
        while (*p) {
            if (*p == 'R') {
                R = true;
                if (flag < 0) {
                    *p = 'a';
                }
                flag++;
            } else if (*p == 'D') {
                D = true;
                if (flag > 0) {
                    *p = 'a';
                }
                flag--;
            }
            p++;
        }
        p = senate;
    }
    if (flag > 0) {
        return "Radiant";
    }
    return "Dire";
}