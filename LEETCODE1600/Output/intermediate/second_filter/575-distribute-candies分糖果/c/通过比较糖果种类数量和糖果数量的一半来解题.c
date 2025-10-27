public class Solution {
    public int DistributeCandies(int[] candies) {
        int max=1;
        Array.Sort(candies);
        for(int i=1;i<candies.Length;i++){
            if(candies[i]!=candies[i-1]){
                max++;
            }
        }
        if(max<candies.Length/2){return max;}
        return candies.Length/2;
    }
}