#define MAX 5200
char * addStrings(char * num1, char * num2){
    int len1 = 0;
    int len2 = 0;
    int retlen = 0;
    int maxlen = 0;
    int minlen = 0;
    int i = 0;
    int jinwei = 0;
    int temp = 0;
    char ret[MAX] = {'\0'};
    char *end = NULL;
    len1 = strlen(num1);
    len2 = strlen(num2);
    maxlen = len1 > len2 ? len1 : len2;
    minlen = len1 < len2 ? len1 : len2;

    // printfprintfprintf("maxlen = %d, minlen = %d\n",maxlen, minlen);

    for(i = 0; i < maxlen; i++) {
        if(minlen - 1 - i >= 0) {
            // printf("(num1[%d - 1 - %d] - \'0\') = %d, (num2[%d - 1 - %d] - \'0\' = %d ",len1, i , (num1[len1 - 1 - i] - '0'), len2, i, (num2[len2 - 1 - i] - '0'));
            temp = jinwei + (num1[len1 - 1 - i] - '0') + (num2[len2 - 1 - i] - '0');
            jinwei = (int)(temp / 10);
            temp = temp % 10;
            // printf("temp = %d, jinwei = %d\n", temp, jinwei);
            ret[i] = (char)('0' + temp);
            // printf(" ret[%d] = %c\n", i, ret[i]);
        }
        else if(minlen == len2){
            // printf("comehere\n");
            temp = jinwei + (num1[len1 - 1 - i] - '0') + 0;
            jinwei = (int)(temp / 10);
            temp = temp % 10;
            ret[i] = (char)('0' + temp);            
        }
        else if(minlen == len1){
            temp = jinwei + 0 + (num2[len2 - 1 - i] - '0');
            jinwei = (int)(temp / 10);
            temp = temp % 10;
            ret[i] = (char)('0' + temp);            
        }    
    }

    if(jinwei != 0) {
        ret[i] = (char)('0' + jinwei);   
        jinwei = 0;
    }

    retlen = strlen(ret);

    end = (char *)malloc((retlen + 1) * sizeof(char));
    memset(end, '\0', (retlen + 1) * sizeof(char));

    for(i = 0; i < retlen; i++) {
        end[retlen - 1 - i] = ret[i];
    }
    // for(i = 0; i < retlen; i++) {
    //    printf("%c",end[i]);
    // }
    // printf("end = %s\n", end);
    return end;
}