bool hasGroupsSizeX(int* deck, int deckSize){
//数组中的数值相同的的个数，所有的个数都能整除最小的（不为1）；
        int i,max=-1,j,min;
        for(i=0;i<deckSize;i++)if(max<deck[i])max=deck[i];
        int a[max+1];
        for(i=0;i<=max;i++)a[i]=0;
        for(i=0;i<deckSize;i++)a[deck[i]]++;
        for(i=0;i<=max;i++)if(a[i]>0){min=a[i];break;}
        for(j=i;j<=max;j++)if(min>a[i])min=a[i];
        for(i=2;i<=min;i++){
            for(j=0;j<=max;j++)if(a[j]%i!=0)break;
            if(j>max)return true;
        }
        return false;
        }