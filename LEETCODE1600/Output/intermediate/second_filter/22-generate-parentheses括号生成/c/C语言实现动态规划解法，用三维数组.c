/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NUM  2000 

int dpLen(char** pStr) {
    int i = 0;
    if (pStr[i] == "") {   // dp【0】是个空字符串集合，但是集合数量是1
        return 1;
    }
    while (strlen(pStr[i]) > 0) {
        i++;
    }
    return i;
}

char ** generateParenthesis(int n, int* returnSize){
    int len = 2 * n + 1;

    char*** dp = (char***)calloc(n + 1, sizeof(char**)); // 因为前面的dp【n-1】也要存储，定义大小为n的三维数组
    for (int i = 0; i < n + 1; i++) {
        dp[i] = (char**)calloc(NUM, sizeof(char*));      // 组合的数量
        for (int j = 0; j < NUM; j++) {             
            dp[i][j] = (char*)calloc(len, sizeof(char));  //每个组合的大小
        }
    }

    dp[0][0] = "";    
    int index = 1; // dp【0】是有一个解的

    for (int i = 1; i <= n; i++) { 
        index = 0;
        for (int j = 0; j < i; j++) {
            int len1 = dpLen(dp[j]); 
            
            for (int k = 0; k < len1; k++) {   //每一个dp[j] 要与每一个dp[i - 1 - j]进行组合
                int len2 = dpLen(dp[i - 1 - j]);
                
                for (int m = 0; m < len2; m++) {
                    char* tmp = (char*) calloc(len, sizeof(char));
                    
                    strcat(tmp, "(");
                    strcat(tmp, dp[j][k]);
                    strcat(tmp, ")");
                    strcat(tmp, dp[i - 1 - j][m]);
                    strcat(dp[i][index++], tmp);

                    free(tmp);
                }
            }            
        }        
    }
    
    *returnSize = index;    
    return dp[n];
}