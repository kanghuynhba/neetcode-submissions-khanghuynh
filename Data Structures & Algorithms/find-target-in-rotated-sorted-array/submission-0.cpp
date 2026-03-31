class Solution {
public:
    int findMin(vector<int>& nums, int left, int right) {
        if(left==right) {
            return left;
        }
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[right]) {
            return findMin(nums, mid+1, right);
        }
        return findMin(nums, left, mid);
    }
    int binarySearch(vector<int>& nums, int& size, int left, int right, int x) {
        if(left>right) {
            return -1;
        }
        int mid=left+(right-left)/2;
        if(x==nums[mid%size]) {
            return mid%size;
        } else if(x<nums[mid%size]) {
            return binarySearch(nums, size, left, mid-1, x);
        } 
        return binarySearch(nums, size, mid+1, right, x);
    }
    int search(vector<int>& nums, int target) {
        int size=nums.size();
        int minId=findMin(nums, 0, size-1);
        return binarySearch(nums, size, minId, size+minId-1, target);
    }
};
