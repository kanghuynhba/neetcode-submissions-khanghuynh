class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) {
            return nums[0];
        }
        int sec=nums[0], prev=max(nums[0], nums[1]); 
        int temp;
        for(int i=2; i<nums.size(); i++) {
            temp=prev;
            prev=max(prev, sec+nums[i]);
            sec=temp;
        }
        return prev;
    }
};

