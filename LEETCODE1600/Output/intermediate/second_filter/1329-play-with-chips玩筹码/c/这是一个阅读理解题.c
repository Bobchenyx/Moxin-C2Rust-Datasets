int minCostToMoveChips(int* chips, int chipsSize){
       int a1=0;//奇数个数
       int a2=0; //偶数个数
       int i;
       for(i=0;i<chipsSize;i++){
           if(chips[i]%2==0)a2++;
           else a1++;
       }  //for
       return a1<a2?a1:a2;
}