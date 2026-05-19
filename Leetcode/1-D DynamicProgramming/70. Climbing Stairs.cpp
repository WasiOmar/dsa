class Solution {
public:
    vector<int>dp;
    int helper(int left){
        if(left == 1 || left == 0){
            return 1;
        }
        if(dp[left]!=0) return dp[left];
        return  dp[left]=helper(left-1)+helper(left-2);
    }
    int climbStairs(int n) {
        dp.resize(n+1,0);
        return helper(n);
    }
};
