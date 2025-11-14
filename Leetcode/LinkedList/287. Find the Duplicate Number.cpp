class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            for (int i = 0; i < nums.size(); i++) {
                int index = abs(nums[i]) - 1;
                if (nums[index] > 0)
                    nums[index] *= -1;
                else
                    return index+1;
            }
    
            return -1;
        }
    };