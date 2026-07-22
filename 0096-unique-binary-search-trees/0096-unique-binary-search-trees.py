class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # The no of the structurally unique bianry seach tree which has n nodes of the unique value
        # from 1 to n is equal to the Catalan Number
        ans = 1

        for i in range(2, n + 1):
            ans = (ans * (4 * i - 2)) // (i + 1)
        return ans