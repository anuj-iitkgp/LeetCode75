class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        num = num / 10 + num % 10
        if num >= 10:
            return self.addDigits(num)
        else:
            return num