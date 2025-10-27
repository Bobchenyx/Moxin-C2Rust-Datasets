class Solution {
    public int[] twoSum(int[] nums, int target) {

        //创建Map对象
        //数据采用的哈希表结构
        Map<Integer,Integer> map= new HashMap<Integer,Integer>();

        for(int i=0;i<nums.length;i++)
        {
            int index=target-nums[i];
            if(map.containsKey(index))
                return new int [] {map.get(index),i};//关键是谁先谁后的问题
            map.put(nums[i],i);
        }

        throw new IllegalArgumentException("no two sum solution!");
        //抛出异常
    }
}