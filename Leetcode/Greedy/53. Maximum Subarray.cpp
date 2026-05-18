class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maxsum = INT_MIN;
    for(auto val: nums){
        sum=max(val,sum+val);
        maxsum=max(maxsum,sum);
    }
    return maxsum; 
    }
};
