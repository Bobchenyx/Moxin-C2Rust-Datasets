char* compressString(char* S){
    int length1=strlen(S);
    char *temp=(char*)malloc(sizeof(char)*length1);
    int index=0,i,count=0,flag=1;
    char prior=S[0];
    for(i=0;i<=length1;i++){//注意此处循环条件为i<=length1，目的是为了将最后一轮的数据输出；
        if(S[i]==prior){
            count++;
        }
        else{
    /*每次往结果数组temp里添加数据时，检查temp数组长度，若长度超过length-1则返回,因为压缩不能使长度减小*/
            if(index>=length1-1){
                flag=0;
                break;
            }
            temp[index++]=prior;
    /*防止同一个字母个数超过10，要逐位显示计数器count的char类型字符*/
            char *nums=(char*)malloc(sizeof(char)*10);
            int k=0;
            while(count!=0){
                int xand=count%10;
                count/=10;
                nums[k++]=xand+'0';
            }
            for(int j=k-1;j>=0;j--){
                if(index>=length1-1){
                    flag=0;
                    break;
                }
                temp[index++]=nums[j];
            }
    /*遍历到一个新的字符，刷新计数器count和标记符prior*/
            count=1;
            prior=S[i];
        }
    }
    if(flag){
        temp[index]='\0';
        return temp;
    }
    else
        return S;
}