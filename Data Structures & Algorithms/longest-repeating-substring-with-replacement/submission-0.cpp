class Solution {
public:
    int maxCount(vector<int>& count, int k) {
        int sum=0, maxCount=0;
        for(int i=0; i<count.size(); i++) {
            sum+=count[i];
            maxCount=max(maxCount, count[i]);
        }
        if(sum-maxCount>k) {
            return 0;
        }
        return sum;
    }
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);  
        int maxNumb=0, curMax;
        int j=0;
        for(int i=0; i<s.size(); i++) {
            count[s[i]-'A']++;
            curMax=maxCount(count, k);
            maxNumb=max(maxNumb, curMax);
            if(curMax==0) {
                count[s[j++]-'A']--;
            }
        }
        return maxNumb;
    }
};
/*
 *  There are 2 decisions I should choose:
 *      1. Should I increment i while I increment j 
 *      once interval [i, j] isn't satisfied the condition.
 *          We need to find an interval that larger than current j-i+1 
 *          (e.g maxCount=max(maxCount, j-i+1));
 *          => We can increment i synchronize with increment j
 *      2. Should I increment j only once interval [i, j] isn't satisfied the condition.
 *  For the case
 *      "AAABBABBB" k=1
 *          ^                
 * */

