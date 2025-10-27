int searchInsert(int* nums, int numsSize, int target){
    int head = 0;
    int rear = numsSize-1;
    if (numsSize == 0){
        return 0;
    }

    while (rear >= 0 && head <numsSize && head <= rear){
        int mid = (head+rear)/2;
        if (nums[mid] == target){
            return mid;
        }
        if (nums[mid] > target){
            rear = mid - 1;
        }
        else{
            head = mid + 1;
        }
    }
    return head;
}
//     if (numsSize == 0){
//         return 0;
//     }
//     if (numsSize == 1){
//         if (nums[0] >= target){
//             return 0;
//         }
//         else{
//             return 1;
//         }       
//     }

//     int i = 0;
//     if (nums[0] < nums[1]){
//         while (i < numsSize && nums[i] < target){
//             i++;
//         }
//     }
//     else{
//         while (i < numsSize && nums[i] > target){
//             i--;
//         }
//     }

//     return i;

// }