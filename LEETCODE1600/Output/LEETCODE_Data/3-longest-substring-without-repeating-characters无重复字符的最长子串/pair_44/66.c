int lengthOfLongestSubstring(char * s){
    int arr[128],start=1,maxlen=0,i,end=1;
    char *p=s;
    memset(arr,0,sizeof(arr));
    for(i=0;s[i];i++){
        if(arr[s[i]]<start) arr[s[i]]=end++;
        else{
            if(end-start>maxlen) maxlen=end-start;
            start=arr[s[i]]+1;
            arr[s[i]]=end++;
        }
    }
    if(end-start>maxlen) maxlen=end-start;
    return maxlen;
}