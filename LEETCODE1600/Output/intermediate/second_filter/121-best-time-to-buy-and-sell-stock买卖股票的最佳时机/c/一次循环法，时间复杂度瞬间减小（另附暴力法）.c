// int maxProfit(int* prices, int pricesSize){
//     int max=0;
//     for(int i=0;i<pricesSize-1;i++){
//         for(int j=i+1;j<pricesSize;j++){
//             int de=prices[j]-prices[i];
//             if(max<de)
//                 max=de;
//         }
        
//     }
//     return max;
// }
int maxProfit(int* prices, int pricesSize){
    int max=0,minprice=60000;
    for(int i=0;i<pricesSize;i++){
            if(minprice>prices[i])
                minprice=prices[i];
            else if(max<prices[i]-minprice){
                max=prices[i]-minprice;
            }
        
    }
    return max;
}