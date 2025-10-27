char * countAndSay(int n){
    if(n == 1)  return "1";
    else if(n == 2) return "11";
    else if(n == 3) return "21";
    else if(n == 4) return "1211";
    else if(n == 5) return "111221";

    char *res = (char *)malloc(10000);
    char *temp = (char *)malloc(10000);
    res[0] = '1'; res[1] = '1';
    res[2] = '1'; res[3] = '2';
    res[4] = '2'; res[5] = '1';
    res[6] = '\0';

    for(int i = 6; i <= n; ++i){
        char key = res[0];
        int count = 1, k = 0;
        for(int j = 1; res[j] != '\0'; ++j){
            if(res[j] == key)   ++count;
            else{
                temp[k++] = '0' + count;
                temp[k++] = key;
                key = res[j];
                count = 1;
            }
        }
        temp[k++] = '0' + count;
        temp[k++] = key;

        for(int j = 0; j < k; ++j){
            res[j] = temp[j];
        }
        res[k] = '\0';
    }

    return res;
}