"""
Source: https://leetcode-cn.com/problems/course-schedule/
Author: Lianfeng Shen
Date:   2019-04-05
"""


from collections import defaultdict


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        G = defaultdict(list)
        for s, f in prerequisites:
            G[f].append(s)
            
        visited = [0] * numCourses
        def dfs(v):
            if visited[v] == 1: return False
            if visited[v] == 2: return True
            
            visited[v] = 1
            for nn in G[v]:
                if not dfs(nn):
                    return False
            
            visited[v] = 2
            return True
            
        for v in range(numCourses):
            if not dfs(v):
                return False
        return True
