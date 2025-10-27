方法一：dfs/回溯+贪心+剪枝
void recursion(int* coins,int coinsSize,int k,int sum,int amount,int* result){
//该用下标为k的硬币了，sum是当前已经用了多少硬币，amount是减去已经凑的钱剩下还应该凑多少钱
    int n = amount/coins[k];
    if(sum+n < (*result)){    //剪枝，用大的硬币都超过当前最好的结果了，不用看用小硬币的情况了
        if(amount%coins[k] == 0){
            *result = sum+n;
        }else if(k+1 < coinsSize){   //else if防止出现没有任何一个组合符合时coins数组越界
            for(int i=n;i>=0;i--){    
                recursion(coins,coinsSize,k+1,sum+i,amount-i*coins[k],result);
            }
        }
    }      
}

int coinChange(int* coins, int coinsSize, int amount){
    if(coinsSize < 1){
        return -1;
    }
    for(int i=0;i<coinsSize;i++){         //简单选择排序，配合贪心算法，从大的硬币开始选
        int max = i;
        for(int j=i+1;j<coinsSize;j++){
            if(coins[j] > coins[max]){
                max = j;
            }
        }
        int temp = coins[i];
        coins[i] = coins[max];
        coins[max] = temp;
    }
    int result = amount+1;
    recursion(coins,coinsSize,0,0,amount,&result);

    return (result==amount+1?-1:result);
}