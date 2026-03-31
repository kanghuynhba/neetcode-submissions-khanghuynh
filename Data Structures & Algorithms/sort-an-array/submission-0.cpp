class Solution {
private:
    vector<int> aux;
public:
    void sort(vector<int>& nums, int low, int high) {
        if(high<=low) {
            return;
        }
        int mid=low+(high-low)/2;
        sort(nums, low, mid);
        sort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    void merge(vector<int>& nums, int low, int mid, int high) {
        int i=low, j=mid+1;
        for(int k=low; k<=high; k++) {
            aux[k]=nums[k];
        }
        for(int k=low; k<=high; k++) {
            if(i>mid) {
                nums[k]=aux[j++];
            } else if(j>high) {
                nums[k]=aux[i++];
            } else if(aux[i]<aux[j]) {
                nums[k]=aux[i++];
            } else {
                nums[k]=aux[j++]; 
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        aux=vector<int>(nums.size(), 0);
        sort(nums, 0, nums.size()-1);         
        return nums;
    }
};
