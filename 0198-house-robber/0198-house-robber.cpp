class Solution {
public:
    int solveRec(vector<int>& nums, int idx){
        if(idx >= nums.size()) return 0;

        // include
        int include = nums[idx] + solveRec(nums, idx + 2);
        // exclude
        int exclude = 0 + solveRec(nums, idx + 1);
        return max(include, exclude);
    }

    int solveMem(vector<int>& nums, int idx, vector<int> & dp){
       if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        // include
        int include = nums[idx] + solveMem(nums, idx + 2, dp);
        // exclude
        int exclude = 0 + solveMem(nums, idx + 1, dp);
         dp[idx] =  max(include, exclude);
        return dp[idx];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solveMem(nums, 0, dp);
    }
};