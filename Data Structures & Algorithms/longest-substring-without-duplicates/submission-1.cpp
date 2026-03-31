class Solution {
public:
    bool checkDup(vector<int>& count) {
        for(int i=0; i<count.size(); i++) {
            if(count[i]>1) {
                return false;
            }
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0);        
        int j=0;
        int maxCount=0;
        for(int i=0; i<s.size(); i++) {
            count[s[i]]++;
            if(checkDup(count)) {
                maxCount=max(maxCount, i-j+1);
            } else {
                count[s[j++]]--;
            }
        }
        return maxCount;
    }
};

