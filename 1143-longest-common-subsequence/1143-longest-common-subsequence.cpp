class Solution {
public:
    int solveRec(string &text1, string &text2, int i, int j ){
        if(i == text1.length()  ) return 0;
        if(j == text2.length() ) return 0;

        if(text1[i] == text2[j]){
            return 1 + solveRec(text1, text2, i + 1, j + 1 );
        }
        else{
            return max(solveRec(text1, text2, i + 1, j  ), solveRec(text1, text2, i , j + 1 ));
        }
    }

    int solveMem(string &text1, string &text2, int i, int j, vector<vector<int>> & dp ){
        if(i == text1.length() || j == text2.length() ) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solveMem(text1, text2, i + 1, j + 1 , dp);

        }
        else{
            return dp[i][j] =  max(solveMem(text1, text2, i + 1, j, dp  ), solveMem(text1, text2, i , j + 1 , dp));
        }
    }
    int solveTab(string &text1, string &text2){
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        for(int i = text1.length() - 1; i>= 0; i--){
            for(int j = text2.length() - 1; j>= 0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];

        }
        else{
            dp[i][j] =  max(dp[i + 1][j], dp[i ][j + 1]);
        }

            }
        }
        return dp[0][0];

        
    }

    int solveSO(string& text1, string & text2){
        vector<int> curr(text2.length() + 1, 0);
        vector<int> next(text2.length() + 1, 0);

        for(int i = text1.length() - 1; i>= 0; i--){
            for(int j = text2.length() - 1; j>= 0; j--){
            int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + next[j + 1];

        }
        else{
            ans =  max(next[j], curr[j + 1]);
        }
        curr[j] = ans;


            }
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        // return solveMem(text1, text2, 0, 0, dp);
        return solveSO(text1, text2);
    }
};