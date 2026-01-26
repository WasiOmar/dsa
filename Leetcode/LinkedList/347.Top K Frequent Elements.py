class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = {}
        
        # Count frequencies
        for n in nums:
            hashmap[n] = hashmap.get(n, 0) + 1

        # Bucket array where index = frequency
        size = len(nums)
        bucket = [[] for _ in range(size + 1)]

        for key, value in hashmap.items():
            bucket[value].append(key)

        result = []
        
        # Loop from highest freq to lowest freq
        for freq in range(size, -1, -1):
            for val in bucket[freq]:
                result.append(val)
                if len(result) == k:
                    return result
