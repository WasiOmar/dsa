class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        per=[[]]

        for num in nums:
            new_perms=[]
            for p in per:
                for i in range(len(p)+1):
                    p_copy=p.copy()
                    p_copy.insert(i,num)
                    new_perms.append(p_copy)
            per=new_perms
        
        return per