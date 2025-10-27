*解法一*/
//获取行数
int getRows(int i, int numRows){
    //如果为奇数
    if ((i/(numRows-1))%2){
        return ((numRows-1)-(i%(numRows-1)));
    }else {
        return (i%(numRows-1));
    }
}

//获取列数
int getColumn(int i, int numRows){
    //如果为奇数
    if ((i/(numRows-1))%2){
        return ((i/(numRows-1) - 1)/2 * (numRows-1) + i%(numRows-1));
    }else {
        return (i/(numRows-1))/2 * (numRows-1);
    }
}

char * convert(char * s, int numRows){
    int column = 0;
    int rows = 0;

    if (s == NULL){
        return NULL;
    }
    int len = strlen(s);
    if (len == 0){
        return s;
    }
    int maxColumn = getColumn(len-1, numRows);
    char** conArray = (char**)malloc(sizeof(char*)*numRows);
    for(int i = 0; i < numRows; i++){
        conArray[i] = (char*)malloc(sizeof(char)*(maxColumn+1));
        memset(conArray[i], 0, sizeof(char)*(maxColumn+1));
    }
    
    for (int i = 0; i < len; i++){
        column = getColumn(i, numRows);
        rows = getRows(i, numRows);
        conArray[rows][column] = s[i]; 
    }
    int k = 0;
    for (int i = 0; i < numRows; i++){
        for(int j = 0; j < maxColumn+1; j++){
            if (conArray[i][j] != 0){        
                s[k++] = conArray[i][j];
            }
        }
    }
    for(int i = 0; i < numRows; i++){
        free(conArray[i]);
        conArray[i] = NULL;
    } 
    free(conArray);
    conArray = NULL;
    return s;
}