int longestValidParentheses(char * s){
    int sLenth = strlen(s);
    int L = 0;
    int R = sLenth - 1;
    int j = 0;
    int i = R;
    int sum = 0;
    int maxLen = 0;

    int *a  = (int*)malloc(sizeof(int) * (sLenth + 1));
    for(int i = 0; i < sLenth; i++) {
        if(s[i] == '(') {
            a[i] = 1;
        }
        if(s[i] == ')') {
            a[i] = -1;
        }
    }

    while(L < R) {
        if(a[L] == -1)
            L++;
        if(a[R] == 1)
            R--;
        if((a[L] == 1) &&(a[R] == -1)) {
            for(j = L; j <= R; j++) {
                sum+= a[j];
                if(sum < 0) {//不满足条件2
                    if(maxLen < (j-L)) {
                        maxLen = j-L;
                    }
                    L = j + 1;
                    sum = 0;
                    break;
                }
            }
            if((j == R + 1) && (sum > 0)) {
                sum = 0;
                for(i = R; i >= L; i--) {
                    sum += a[i];
                    if(sum > 0) {//不满足条件3
                        if(maxLen < (R - i)) {
                            maxLen = R - i;
                        }
                        R = i - 1;
                        sum = 0;
                        break;
                    }
                }
            }
            if(((j == R + 1) || (i == L - 1)) && (sum == 0)) {//满足条件1 2 3，符合有效子串要求
                if(maxLen < (R - L + 1)) {
                    maxLen = R - L + 1;
                }
                break;
            }
        }
    }
    return maxLen;
}