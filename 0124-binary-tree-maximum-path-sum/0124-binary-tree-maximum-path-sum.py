# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        self.maxPathSum = float("-inf")

        def pathSum(root):
            if root is None:
                return 0
            left = max(0, pathSum(root.left))  
            right = max(0,pathSum(root.right))
            self.maxPathSum = max(self.maxPathSum, left + right + root.val)
            return max(left, right) + root.val
        pathSum(root)
        return self.maxPathSum
        