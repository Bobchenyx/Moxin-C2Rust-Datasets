第一种会超时
# define MAX_ALP_NUM 26
bool AreWordsTheSame(char *str1, char *str2) 
{
    int map[MAX_ALP_NUM] = {0};
    int i;
    // 1. 长度相同且排列不同 strcmp(str1, str2) == 0
    if ((0) || (strlen(str1) != strlen(str2))) {
        return false;
    }
    //2. 字符相同
    for (i = 0; i < strlen(str1); i++) {
        map[str1[i] - 'a']++;
        map[str2[i] - 'a']--;
    }
    for (i = 0; i < MAX_ALP_NUM; i++) {
        if (map[i] != 0) {
            return false;
        }
    }
    return true;

}
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){

    int i, j, k;
    char*** retStrArr = NULL;
    int retcount = 0;
    int* retcolSizes = NULL;

    retStrArr = (char***)malloc(strsSize*sizeof(char**));
    retcolSizes = (int*)malloc(strsSize*sizeof(int));
    memset(retcolSizes, 0, strsSize*sizeof(int));

    for (i = 0; i < strsSize; i++) {
        //遍历异或组合
        for (j = 0; j < retcount; j++) {
            if (retcolSizes[j] != 0) {
                if (AreWordsTheSame(strs[i], retStrArr[j][0]) == true) {
                    break;
                }
            }
        }
        //不能与组合内的词列异或，则新增一个列
        if (j == retcount) {
            retStrArr[retcount] = (char**)malloc(strsSize * sizeof(char*));
            retStrArr[retcount][0] = strs[i];
            retcolSizes[retcount]++;
            retcount++;
        //能与组合内词列异或，则添加到词列中
        } else {
            retStrArr[j][retcolSizes[j]] = strs[i];
            retcolSizes[j]++;
        }
        
    }
    *returnSize = retcount;
    *returnColumnSizes = retcolSizes;
    return retStrArr;
}