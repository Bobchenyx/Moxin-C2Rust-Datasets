char * findLongestWord(char * s, char ** d, int dSize){
    char *result = "";
    int max = -1;
    for (int i = 0; i < dSize; ++i) {
        char *p = s, *q = d[i];
        int j = 0, k = 0;
        while (p[j] != '\0' && q[k] != '\0') {
            if (p[j] == q[k]) {
                ++k;
            } 
            ++j;
        }
        if (q[k] == '\0') {
            if (k > max) {
                max = k;
                result = q;
            } else if (k == max) {
                if (q[0] - result[0] < 0) {
                    max = k;
                    result = q;
                }
            } else {

            }
        }
    }
    
    return result;
}