class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int size=nums.size();
        int curMaxSum=0, curMinSum=0;
        int maxSum=INT_MIN, minSum=INT_MAX;
        int sum=0;
        for(int i=0; i<size; i++) {
            sum+=nums[i]; 
            curMaxSum=max(curMaxSum+nums[i], nums[i]);
            curMinSum=min(curMinSum+nums[i], nums[i]);
            minSum=min(minSum, curMinSum);
            maxSum=max(maxSum, curMaxSum);
        }
        if(sum==minSum) {
            return maxSum;
        }
        return max(maxSum, sum-minSum);
    }
};
