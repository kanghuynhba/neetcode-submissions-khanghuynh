
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0; i<k; i++) {
            while(!dq.empty() && nums[dq.back()]<nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        } 
        vector<int> ans;
        ans.push_back(nums[dq.front()]);
        /*
        [1,2,1,3,4,2,1,2]
        deque:[{2,1},{1,2}] ans:[2]
        deque:[{3,3}] ans:[2]
        */
        for(int i=k; i<nums.size(); i++) {
            while(!dq.empty() && nums[dq.back()]<nums[i]) {
                dq.pop_back(); 
            }
            dq.push_back(i);
            while(!dq.empty() && dq.front()<i-k+1) {
                dq.pop_front();   
            } 
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};