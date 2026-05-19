class Solution {
public:
    vector<int>dp;
    int helper(vector<int>&nums,int index){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        return dp[index]= max(helper(nums,index+1), nums[index] + helper(nums,index+2));
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return helper(nums,0);
    }
};