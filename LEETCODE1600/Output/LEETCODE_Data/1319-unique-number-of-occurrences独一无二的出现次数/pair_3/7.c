bool uniqueOccurrences(int* arr, int arrSize){
    int i,j;
    bool temp=true;
    int *count1=(int *)malloc(sizeof(int)*2001);
    memset(count1,0,sizeof(int)*2001);
    int *count2=(int *)malloc(sizeof(int)*(arrSize+1));//数组最长的情况就是arr数组中的每个数都不一样，count且最大数为arrSize
    memset(count2,0,sizeof(int)*(arrSize+1));
    for(i=0;i<arrSize;i++){
        if(arr[i]>=0)
            count1[arr[i]]++;
        else
            count1[arr[i]+2000]++;
    }
    for(j=0;j<2001;j++){
        if(count1[j]>0)
            count2[count1[j]]++;
        if(count2[count1[j]]>1)
            temp=false;
    }
    free(count1);
    free(count2);
    return temp;
}