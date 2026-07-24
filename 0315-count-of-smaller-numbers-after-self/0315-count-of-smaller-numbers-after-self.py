
from sortedcontainers import SortedList
class Solution(object):
    def countSmaller(self, nums: List[int]) -> List[int]:
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        sorted_list = SortedList([])
        result = []

        for i in range(len(nums) - 1, -1, -1):
            num = nums[i]
            idx = sorted_list.bisect_left(num)
            result.append(idx)
            sorted_list.add(num)
        return result[::-1]
        