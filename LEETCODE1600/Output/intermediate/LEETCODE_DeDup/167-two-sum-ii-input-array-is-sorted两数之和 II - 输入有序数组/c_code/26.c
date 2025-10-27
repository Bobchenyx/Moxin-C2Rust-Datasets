python []
def twoSum(nums: int, target: int) ->list:
    sort_nums = list(sorted(range(len(nums)),key=lambda k: nums[k]))
    head = 0
    tail = len(nums) - 1
    temp_sum = nums[sort_nums[head]] + nums[sort_nums[tail]]
    while temp_sum != target:
        if temp_sum > target:  # 大了，尾巴移动
            tail -= 1
        else:  # 小了，头部移动
            head += 1
        # 更新总和
        temp_sum = nums[sort_nums[head]] + nums[sort_nums[tail]]
    return [sort_nums[head], sort_nums[tail]]