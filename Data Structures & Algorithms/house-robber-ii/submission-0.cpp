class Solution {
public:
    int robNotCircle(vector<int>& nums, int l, int r) {
        int first=nums[l];
        int second=max(nums[l], nums[l+1]);
        int temp;
        for(int i=l+2; i<=r; i++) {
            temp=second;
            second=max(second, first+nums[i]);
            first=temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int size=nums.size(); 
        if(size==1) {
            return nums[0];
        } else if(size==2) {
            return max(nums[0], nums[1]);
        }    
        return max(robNotCircle(nums, 0, size-2), robNotCircle(nums, 1, size-1));
    } 
};
