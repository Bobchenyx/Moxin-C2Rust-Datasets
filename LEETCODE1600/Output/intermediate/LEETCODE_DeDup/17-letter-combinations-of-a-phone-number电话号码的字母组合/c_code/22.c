char ** letterCombinations(char * digits, int* returnSize){
    if(!(*digits)){
        *returnSize=0;
        return NULL;
    }

    //按键映射
    char keyMap[10][4]={
        {'\0','\0','\0','\0'},  //'0'
        {'\0','\0','\0','\0'},  //'1'
        {'a','b','c',   '\0'},  //'2'
        {'d','e','f',   '\0'},  //'3'
        {'g','h','i',   '\0'},  //'4'
        {'j','k','l',   '\0'},  //'5'
        {'m','n','o',   '\0'},  //'6'
        {'p','q','r','s'    },  //'7'
        {'t','u','v',   '\0'},  //'8'
        {'w','x','y','z'    }   //'9'
    };

    //按键映射值数量
    int keyValueQty[10]={0,0,3,3,3,3,3,4,3,4};
    
    
    //获取字符串长度
    //初始化待返回数据
    *returnSize=1;
    int strLength = 0;
    while(digits[strLength]){
        if(keyValueQty[digits[strLength]-'0']){
             (*returnSize)*=keyValueQty[digits[strLength]-'0'];
        }      
        strLength++;       
    }
    char** returnStrs = (char**)malloc(sizeof(char*)*(*returnSize));
    int count = 0;
    
    //当前按键映射值编码（即字符索引序列）
    int* keyValues = (int*)malloc(sizeof(int)*strLength);
    memset(keyValues,0,sizeof(int)*strLength);
    
    while(keyValues[0]<keyValueQty[digits[0]-'0']){
        //保存待返回的字符串
        returnStrs[count] = (char*)malloc(strLength+1);
        returnStrs[count][strLength] = '\0';
        for(int i=0;i<strLength;i++){
            returnStrs[count][i] = keyMap[digits[i]-'0'][keyValues[i]];
        }
        count++;

        //每一次排列就是对按键映射编码进行加1操作
        //编码的每一位超过上限值时就要置零并向前进位，就像进制数进位一样
        for(int i=strLength-1;i>=0;i--){
            keyValues[i]++;
            if(keyValues[i]<keyValueQty[digits[i]-'0'])
                break;
            else if(i>=1)
                keyValues[i]=0;             
        }   
    }
    
    free(keyValues);
    return returnStrs;
    
}