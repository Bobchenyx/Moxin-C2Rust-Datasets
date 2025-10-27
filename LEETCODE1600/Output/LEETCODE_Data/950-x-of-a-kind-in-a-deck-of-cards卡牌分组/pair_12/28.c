bool hasGroupsSizeX(int* deck, int deckSize){
    int A[1000]={0};
    int i=0,sum=0;
    for(i=0;i<deckSize;i++){
        if(A[deck[i]]==0){
            sum++;
        }
        A[deck[i]]++;
    }
    int min=deck[0];
    for(i=1;i<deckSize;i++){
        if(A[deck[i]]<A[min]){
            min=deck[i];
        }
    }
    min=A[min];
    if(min<2){
        return false;
    }
    while(min>1){
        int flag=0;
        for(i=0;i<deckSize;i++){
            if(A[deck[i]]%min!=0){
                min--;flag++;
                break;
            }
        }
        if(flag==0){
            return true;
        }
    }
    return false;
}