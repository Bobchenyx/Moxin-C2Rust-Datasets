int cmp(const void* a,const void* b){
    if(*(int*)a<*(int*)b){
        return -1;
    }
    else if(*(int*)a==*(int*)b){
        return 0;
    }
    else{
        return 1;
    }
}

int distributeCandies(int* candies, int candiesSize){
    if(candies==NULL||candiesSize==0){
        return 0;
    }
    qsort(candies,candiesSize,sizeof(int),cmp);
    int typeCount = 1;
    int halfOfCount = candiesSize/2;
    for(int i=1;i<candiesSize;i++){
        if(candies[i]!=candies[i-1]){
            typeCount++;
        }
    }
    if(typeCount<=halfOfCount){
        return typeCount;
    }
    else{
        return halfOfCount;
    }
}