class Solution {
public:
    int binary_search(vector<int>& nums, int left, int right) {
        if(left==right) {
            return nums[left];
        }
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[right]) {
            return binary_search(nums, mid+1, right);
        }     
        return binary_search(nums, left, mid);
    }
    int findMin(vector<int> &nums) {
        return binary_search(nums, 0, nums.size()-1); 
    }
};

/*
 *  where could the min possibly locate? why?
 *      
 * */ 
