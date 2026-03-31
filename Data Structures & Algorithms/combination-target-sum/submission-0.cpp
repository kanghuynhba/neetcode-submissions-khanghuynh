class Solution {
public:
    void dfs(vector<vector<int>>& ans, 
            vector<int>& poss, vector<int>& nums, 
            int start, int target) {
        if(target==0) {
            ans.push_back(poss);
            return;
        } else if(target<0) {
            return;
        }
        for(int i=start; i<nums.size(); i++) {
            poss.push_back(nums[i]);
            dfs(ans, poss, nums, i, target-nums[i]);
            poss.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> poss;
        dfs(ans, poss, nums, 0, target);
        return ans;
    }
};
