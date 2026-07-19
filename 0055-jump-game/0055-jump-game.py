class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        right = 0
        last = len(nums) - 1
        
        for i in range(len(nums)):
            # If current index is unreachable, stop
            if i > right:
                return False
            
            # Update the furthest reachable index
            if i + nums[i] > right:
                right = i + nums[i]
                
            # If we can reach the last index, return True
            if right >= last:
                return True
                
        return False
