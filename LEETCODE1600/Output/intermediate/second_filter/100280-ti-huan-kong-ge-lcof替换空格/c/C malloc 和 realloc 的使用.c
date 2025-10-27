char* replaceSpace(char* s){
        int n = 0;
        for(int i = 0; s[i] != '\0'; ++i) {
            ++n;
        }
        // printf("%d", n);
        char* res;
        res = (char*)malloc(3 * (n + 3) * sizeof(char));
        int k = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] != ' '){
                res[k++] = s[i];
            }else {
                res[k++] = '%';
                res[k++] = '2';
                res[k++] = '0';
            }
        }
        res[k] = '\0';
        return res;
    }