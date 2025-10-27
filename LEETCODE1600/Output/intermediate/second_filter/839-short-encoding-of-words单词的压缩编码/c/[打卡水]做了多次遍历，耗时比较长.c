bool sub(char *a,int al,char *b,int bl);
int len(char *a){
    int i;
    for(i=0;a[i];i++);
    return i;
}

int minimumLengthEncoding(char ** words, int wordsSize){
int i,j,num=wordsSize;
int *queue=(int *)malloc(sizeof(int)*wordsSize);
for(i=0;i<wordsSize;i++){
    queue[i]=len(words[i]);
}
for(i=0;i<wordsSize;i++){
    for(j=0;j<wordsSize;j++){
        // printf("%d,%d\n",queue[i],queue[j]);
        if((queue[i])&&(j!=i)&&(queue[j]>=queue[i])&&sub(words[i],queue[i],words[j],queue[j])){
            queue[i]=0;
            num--;
            break;
        }
    }
}
for(i=0,j=0;i<wordsSize;i++){
    j+=queue[i];
}
return j+num;
}

// a在不在b的尾部
bool sub(char *a,int al,char *b,int bl){
    int i,j;
    if(al>bl) return false;
    for(i=al-1,j=bl-1;i>=0&&j>=0;i--,j--){
        if(a[i]!=b[j]) return false;
    }
    return true;
}