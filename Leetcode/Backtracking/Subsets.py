from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        subset = []

        def dfs(i):
            if i >= len(nums):
                res.append(subset.copy())
                return
            
            # include 
            subset.append(nums[i])
            dfs(i + 1)
            
            # backtrack and remove last element
            subset.pop()
            
            # exclude 
            dfs(i + 1)

        dfs(0)
        return res