class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int x) {
        if(left<=right) {
            int mid=left+(right-left)/2;
            if(nums[mid]==x) {
                return mid;
            } else if(nums[mid]>x) {
                return binarySearch(nums, left, mid-1, x);
            }
            return binarySearch(nums, mid+1, right, x);
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size=numbers.size();
        int id2;
        for(int i=0; i<numbers.size(); i++) {
            id2=binarySearch(numbers, 0, size-1, target-numbers[i]);
            if(id2!=-1) {
                return {i+1, id2+1};
            }
        }
        return {};
    }
};
