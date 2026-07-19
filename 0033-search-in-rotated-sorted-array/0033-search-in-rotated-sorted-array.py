class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = 0
        r = len(nums) - 1

        # while l <= r:
        #     mid = (r - l) // 2 + l
        #     if nums[mid] < target:
        #         l = mid + 1
        #     if nums[mid] > target:
        #         r = mid - 1
        #     if nums[mid] != target:
        #         return -1
        # return mid

        for i in range(len(nums)):
            if nums[i] == target:
                return i
        return -1

        