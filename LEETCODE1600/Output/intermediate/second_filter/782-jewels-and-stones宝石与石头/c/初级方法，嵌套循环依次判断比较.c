int numJewelsInStones(char * J, char * S){
    int count=0;
    for(int i=0;i<strlen(J);i++)
        for(int j=0;j<strlen(S);j++)    //可以改进，从S中第一次出现J中元素的位置开始比较节省时间复杂度
        {
            if(S[j]==J[i])
            count=count+1;
        }
        return count;
}