/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int* res = (int*)malloc(num_people*sizeof(int));
    memset(res, 0, sizeof(int)*num_people);     //用于初始化res
    *returnSize = num_people;
    for(int i=0;candies>0;i++){         //candies表剩余总糖果,i+1表本次本应分配数
        if (i+1<=candies) {   //糖果够用
            res[i%num_people]+=i+1;
            candies-=i+1;
        }else{                //糖果最后一次分配不足
            res[i%num_people]+=candies;
            candies=0;
        }
    }
    return res;
}