class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxi = max( nums[i], maxi);
        }


        int nat_sum = (maxi * (maxi + 1)) /2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(maxi == nums[i]){
                cnt++;
            }
        }
        
        if(cnt > 2) return false;
        else if( sum == nat_sum + maxi) return true;
        return false;
    }
};