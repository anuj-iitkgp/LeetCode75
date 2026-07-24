from collections import defaultdict
class Solution(object):
    def maximalNetworkRank(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        graph = collections.defaultdict(set)

        for city1, city2 in roads:
            graph[city1].add(city2)
            graph[city2].add(city1)

        res = 0
        for city1, city2 in itertools.combinations(range(n), 2):
            has_connection = 1 if city1 in graph[city2] else 0
            city1_connection = len(graph[city1])
            city2_connection = len(graph[city2])
            res = max(res, city1_connection + city2_connection - has_connection)
        return res