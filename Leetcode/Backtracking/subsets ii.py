class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def backtrack(index: int, subset: List[int]):
            if index == len(nums):
                res.append(subset[:])
                return

            # TAKE
            subset.append(nums[index])
            backtrack(index + 1, subset)
            subset.pop()

            # SKIP duplicates
            while index + 1 < len(nums) and nums[index] == nums[index + 1]:
                index += 1

            # NOT TAKE (after skipping all duplicates)
            backtrack(index + 1, subset)

        backtrack(0, [])
        return res