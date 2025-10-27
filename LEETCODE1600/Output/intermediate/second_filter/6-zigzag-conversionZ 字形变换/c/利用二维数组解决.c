char *convert(char *s, int numRows)
{
    int len = strlen(s);
    /* 针对极端情况 */
    if(numRows > len) {
        return s;
    }
    if(numRows == 1) {
        return s;
    }
    
    int row = 0; /* 二维数组行数 */
    int col = 0; /* 二维数组列数 */
    int index = 0; /* 输入数组索引 */
    
    char arr[1001][1001] = {0}; /* 存放元素的二维数组 */
    char* arr1 = (char*)malloc(sizeof(char)*1001); /* 返回的一维数组 */
    memset(arr1,0,1001); /* 对数组初始化 */
    
    /* 通过二维数组实现按列存储s[index]，通过边界值row < numRows，以及row来转换方向 */
    while(s[index]) {
        while(row < numRows && s[index]) {
            arr[row++][col] = s[index++];
        }
        /* 当row = numRows - 1时 */
        row -= 2;
        col++;
        while(row && s[index]) {
            arr[row--][col++] = s[index++];
        }
    }
    
    /* 二维数组转换为一维数组 */
    int ret = 0;
    for(int i = 0;i < numRows;i++) {
        for(int j = 0;j < col;j++) {
            if(arr[i][j]) { /* 只存储有数值的数字，空字符跳过 */
                arr1[ret++] = arr[i][j];
            }
        }
    }
    
    return arr1;
    
}

// 作者：fuchao
// 链接：https://leetcode-cn.com/problems/zigzag-conversion/solution/cyu-yan-li-yong-er-wei-shu-zu-lai-zhuan-bian-fang-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。