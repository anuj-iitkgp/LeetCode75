class Solution {
public:
    void printAllSubsets(int idx, vector<int>& ds,
                         vector<int>& nums,
                         vector<vector<int>>& ans) {

        if (idx == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // Pick
        ds.push_back(nums[idx]);
        printAllSubsets(idx + 1, ds, nums, ans);
        ds.pop_back();

        // Not Pick
        printAllSubsets(idx + 1, ds, nums, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;

        printAllSubsets(0, ds, nums, ans);

        return ans;
    }
};