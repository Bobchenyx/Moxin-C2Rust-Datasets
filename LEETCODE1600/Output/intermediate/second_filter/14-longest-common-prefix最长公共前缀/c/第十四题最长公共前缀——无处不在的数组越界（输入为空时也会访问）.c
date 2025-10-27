int checkIfEnd(char ** strs, int sub, int strsSize){  // 检查当前下标是否已经是某一串的结尾
    for(int i=0;i<strsSize;i++){
        if(strs[i][sub]=='\0'){
            return 1;
        }
    }
    return 0;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int subscript = 0;
    int breakFlag = 0;
    char * result = (char *)malloc(sizeof(char) * (strsSize + 5));

    // 单独处理传入为空的情况
    if(strsSize==0){    // 易错部分，不加这个会发生下标越界。具体原因是我的程序总是会访问strs[0][0]，即便它是空的
        result = "";
        return result;
    }

    while(true){
        if(checkIfEnd(strs,subscript,strsSize)==1)break;
        for(int i=0;i<strsSize;i++){
            if(strs[i][subscript]!=strs[0][subscript])breakFlag = 1;
        }
        if(breakFlag==1)break;
        else{
            result[subscript++] = strs[0][subscript];
        }
    }
    result[subscript] = '\0';
    return result;
}