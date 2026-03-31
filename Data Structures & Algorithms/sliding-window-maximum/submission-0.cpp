
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        for(int i=0; i<k; i++) {
            while(!dq.empty() && dq.back().first<nums[i]) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
        } 
        vector<int> ans;
        ans.push_back(dq.front().first);
        /*
        [1,2,1,3,4,2,1,2]
        deque:[{2,1},{1,2}] ans:[2]
        deque:[{3,3}] ans:[2]
        */
        for(int i=k; i<nums.size(); i++) {
            while(!dq.empty() && dq.back().first<nums[i]) {
                dq.pop_back(); 
            }
            dq.push_back({nums[i], i});
            while(!dq.empty() && dq.front().second<i-k+1) {
                dq.pop_front();   
            } 
            ans.push_back(dq.front().first);
        }
        return ans;
    }
};