class Solution {
public:
    int solveRec(int m, int n, int down, int right){

        if(down == m - 1 && right == n - 1) return 1;
        if(down >= m || right >= n) return 0;

        int down1 = solveRec(m , n, down + 1, right);
        int right1 = solveRec(m , n,  down , right + 1);

        int ans = down1 + right1;
        return ans;

    }

    int solveMem(int m, int n, int down, int right, vector<vector<int>> & dp){

        if(down == m - 1 && right == n - 1) return 1;
        if(down >= m || right >= n) return 0;

        if(dp[down][right] != -1) return dp[down][right];

        int down1 = solveMem(m , n, down + 1, right, dp);
        int right1 = solveMem(m , n,  down , right + 1, dp);

        dp[down][right] = down1 + right1;
        return dp[down][right];

    }

 
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solveMem(m, n, 0, 0,dp);
    }
};