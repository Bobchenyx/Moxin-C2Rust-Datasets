/*方法一：莽就完事了*/
// int maxArea(int* height, int heightSize){
//     int i, j;
//     int max = 0;
//     int size = 0;
//     for (i=0; i<heightSize; i++){
//         for (j=i+1; j<heightSize; j++){
//             size = minNum(height[i], height[j])*(j-i);
//             if (size > max){
//                 max = size;
//             }
//         }
//     }
//     return max;

// }

int minNum(int i, int j){
    if (i > j){
        return j;
    }
    else{
        return i;
    }
}
/*方法二：动脑*/
int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize-1;
    int max = minNum(height[left], height[right])*(right-left);
    while (left < right){
        if (height[left] <= height[right]){
            left++;
            if (height[left] > height[left-1]){//只有新来的比原来的高，那么才需要判定面积
                if (minNum(height[left], height[right])*(right-left) > max){
                max = minNum(height[left], height[right])*(right-left);
                }
            }

        }
        else{
            right--;
            if (height[right] > height[right+1]){
                if (minNum(height[left], height[right])*(right-left) > max){
                max = minNum(height[left], height[right])*(right-left);
                }
            }
        }

    }
    return max;
}