class Solution:
    def combinationSum(self, nums, target):
        res = []
        sub = []

        def d(i, remaining):
            if remaining == 0:
                res.append(sub.copy())
                return
        
            if i >= len(nums) or remaining < 0:
                return

        # choose current number (reuse allowed)
            sub.append(nums[i])
            d(i, remaining - nums[i])   # 🔑 stay at i

            # backtrack
            sub.pop()

            # skip current number
            d(i + 1, remaining)

        d(0, target)
        return res