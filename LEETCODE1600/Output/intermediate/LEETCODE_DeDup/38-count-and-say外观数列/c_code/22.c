#define MAXSIZE 4096*2
char * countAndSay(int n){
    int count, val;
    int i, j;
    char *res = malloc(MAXSIZE);
    char *temp = malloc(MAXSIZE);
    char buf[16] = {0};
    
    memset(temp, 0 , MAXSIZE);
    memset(res, 0 , MAXSIZE);

    res[0] = '1';
    for(i = 1; i < n; i++) {
        j = 0;
        count = 1;
        while(res[j] != 0){
            while(res[j] == res[j+1]){
                count++;
                j++;
            }
            sprintf(buf,"%d%c", count, res[j]);
            strcat(temp, buf);
            count = 1;
            j++;
        }
        strcpy(res, temp);
        memset(temp, 0 , strlen(temp));
    }

    return res;
}