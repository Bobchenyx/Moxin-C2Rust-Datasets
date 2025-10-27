char* compressString(char* S){
    char ret[100000];
    int i = 0;
    int k = 0;
    int j = 0;

    while (j<strlen(S)){
        j = i+1;
        ret[k++] = S[i];
        while (S[j] != '\0' && S[i] == S[j]){
            j++;
        }
       
        int cnt = 0;
        int temp = j-i;
        int nums[6] = {0};
        while (temp > 0){
            nums[cnt++] = temp%10;
            temp /= 10;
        }
        while (cnt>0){
            ret[k++] = (char)('0'+nums[--cnt]);
        }
        i = j;
    }
    ret[k] = '\0';

    return strlen(ret) < strlen(S) ? ret : S;

}