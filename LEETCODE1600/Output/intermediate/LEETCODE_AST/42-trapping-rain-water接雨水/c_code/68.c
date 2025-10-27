int trap(int* height, int heightSize){
/*
                       top2 == top1 
                        __     __
                       |  |   |  |
           __          |  |   |  |   __            __
          |  |    __   |  |   |  |  |  |    __    |  |
    __    |  |   |  |  |  |   |  |  |  |   |  |   |  |
   |__|___|__|___|__|__|__|___|__|__|__|___|__|___|__|

 */
        /*double pointer */
        int result = 0;
        int left_index = 0;
        int right_index = heightSize - 1;
        int left_max = 0, right_max = 0;
        
        if (heightSize < 2) {
                result = 0;
                goto out;
        }
        
        left_max = height[left_index];
        right_max = height[right_index];

        while(right_index - left_index >= 1) {
                if(left_max <= right_max) {
                        //calcute left
                        result += (left_max - height[left_index] > 0) ? (left_max - height[left_index]) :0;
                        left_index++;
                        //update left max
                        left_max = left_max > height[left_index] ? left_max : height[left_index];
                }
                else {
                        //calcute right
                        result += (right_max - height[right_index] > 0) ? (right_max - height[right_index]) : 0;
                        right_index--;
                        //update right_max
                        right_max = right_max > height[right_index] ? right_max : height[right_index];
                }
        }

out:
        return result;

}