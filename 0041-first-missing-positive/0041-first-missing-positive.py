class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. check 1 is present or not
        if not nums or 1 not in nums:
            return 1
        
        for i, num in enumerate(nums):
            if (num <= 0 or num > len(nums)):
                nums[i] = 1
        
        for i, num in enumerate(nums):
            to_change = nums[abs (num) - 1]

            if to_change > 0:
                nums[abs (num) - 1] *= -1
        
        for i in range(len(nums)):
            if nums[i] > 0:
                return i + 1

        return len(nums) + 1