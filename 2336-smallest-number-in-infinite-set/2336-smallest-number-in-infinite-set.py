class SmallestInfiniteSet(object):

    def __init__(self):
        self.smallest = 1
        self.remove = set()
        

    def popSmallest(self):
        """
        :rtype: int
        """
        ret = self.smallest
        self.remove.add(ret)
        self.smallest += 1
        while self.smallest in self.remove:
            self.smallest += 1
        return ret
        

    def addBack(self, num):
        """
        :type num: int
        :rtype: None
        """
        if num in self.remove:
            self.remove.remove(num)
            if num < self.smallest:
                self.smallest = num
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)