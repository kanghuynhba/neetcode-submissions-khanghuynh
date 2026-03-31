class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size=nums.size();
        unordered_set<int> check;
        for(int num : nums) {
            check.insert(num);
        }        
        int count=0, maxCount=0;
        for(int num : nums) {
            if(check.find(num-1)==check.end()) {
                count=0;
                for(int i=num; i<=num+size; i++) {
                    if(check.find(i)!=check.end()) {
                        count++;
                    } else {
                        break;
                    }
                }
                maxCount=max(maxCount, count);
            }
        }
        return maxCount;
    }
};