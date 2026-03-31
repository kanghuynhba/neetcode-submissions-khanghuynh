class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool flag=false;
        int zeroId=-1;
        vector<int> ans(nums.size(), 0);
        int product=1;
        for(int i=0; i<nums.size(); i++) {
            if(flag && nums[i]==0) {
                return ans;
            } else if(nums[i]==0) {
                flag=true;
                zeroId=i;
            } else {
                product*=nums[i];
            }
        }
        if(flag) {
            ans[zeroId]=product;
            return ans;
        }
        for(int i=0; i<nums.size(); i++) {
            ans[i]=product/nums[i];        
        }
        return ans;
    }
};
