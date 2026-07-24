class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # Brute Force
        # ans = [1] * len(nums)

        # for i in range(len(nums)):
        #     for j in range(len(nums)):
        #         if i != j:
        #             ans[i] *= nums[j]
        # return ans

        ans = [1] * len(nums)
        i = 1

        while i < len(nums):
            ans[i] = ans[i - 1] * nums[i - 1]

            i += 1

        prod = 1
        j = len(nums) - 2

        while j >= 0:
            prod *= nums[ j + 1]

            ans[j] *= prod
            j -= 1

        return ans
