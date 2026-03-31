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

/*
 *  So the array is circled
 *
 *  Example:
 *      [1,2,1] -> 2    
 *      [1,2,3,4] -> 6
 *      [1,2,3,2,1,2] -> 6
 *      [5] -> 5
 *      [3,4] -> 4
 *      [2,3,4] -> 4
 *  Question:
 *      Is this an empty array?
 *      maybe what is the size of the array?
 *
 *  Idea:
 *      if the array is not circled
 *          we will try dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
 *      In this case the array is circled
 *          we will try the same pattern for max([0, size-2], [1, size-1]) 
 *          it required the nums.size() >= 2
 *  Dry run:
 *      [2,1,3,4] -> 5
 *      [2,1,3] -> 5
 *      [1,3,4] -> 5
 *      [2,3,4] -> 4
 *      [2,3] -> 3
 *      [3,4] -> 4 => 4
 * */
