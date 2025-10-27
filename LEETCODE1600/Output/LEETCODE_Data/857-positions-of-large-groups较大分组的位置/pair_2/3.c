int** largeGroupPositions(char * S, int* returnSize, int** returnColumnSizes){
    int len = strlen(S);
    //申请一个长度为字符串1/3的数组，必定够用
    int** res = (int**)malloc(sizeof(int*) * (len/3));
    char temp;
    int i=0, j, m=0; //i，j指针遍历S字符串，m指向结果数组
    while(i < len){
        temp = S[i];
        j = i+1;
        while(j < len && S[j] == temp){ //j停在不同于i的下一个数上
            j++;
        }
        if(j-i >= 3){ //如果大于等于三个，存入结果中
            res[m] = (int*)calloc(2, sizeof(int)); //结果数组申请空间
            res[m][0] = i;
            res[m][1] = j-1;
            (*returnColumnSizes)[m] = 2;
            m++;
        }
        i = j;
    }
    *returnSize = m;
    return res;
}