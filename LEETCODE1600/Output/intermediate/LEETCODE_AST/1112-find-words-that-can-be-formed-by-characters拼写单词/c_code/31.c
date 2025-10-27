int countCharacters(char ** words, int wordsSize, char * chars){
    int *logs=(int *)malloc(strlen(chars)*sizeof(int));
    for(int i=0;i<strlen(chars);i++){//置0
        logs[i]=0;
    }
    int count=0;
    for(int i=0;i<wordsSize;i++){//遍历每个单词
        int len=strlen(chars);
        int count0=0;
        char * temp=words[i];
        while(*words[i]){//统计匹配字符
            char c=*words[i];
            int j=0;
            while(j<len){//相似则在数组中作好相应标记
                if(c==chars[j]&&logs[j]==0){
                    logs[j]=1;
                    count0++;
                    break;
                }
                j++;
            }
        words[i]++;
        }
        int sm=0;
        for(int s=0;s<len;s++){//统计标记数
            if(logs[s]==1) sm++;
        }
        if(sm==strlen(temp)) count+=count0;//对比标记数，相同则统计入总计
        for(int z=0;z<len;z++){//数组置0，继续统计下个单词
        }
    }
    return count;
}