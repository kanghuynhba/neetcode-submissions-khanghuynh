class Solution {
public:
    string longestPalindrome(string s) {
        int maxOdd=1, maxEven=0;
        int size=s.size();
        int l, r;
        int countOdd, countEven;
        int oddId, evenId;
        for(int i=0; i<size; i++) {
            l=i-1;
            r=i+1;
            countOdd=1;
            while(l>=0 && r<size && s[l]==s[r]) {
                l--;
                r++;
                countOdd+=2;
            }
            if(maxOdd<=countOdd) {
                maxOdd=countOdd;
                oddId=l+1;
            }
        }
        for(int i=0; i<size; i++) {
            l=i;
            r=i+1;
            countEven=0;
            while(l>=0 && r<size && s[l]==s[r]) {
                l--;
                r++;
                countEven+=2;
            }
            if(maxEven<=countEven) {
                maxEven=countEven;
                evenId=l+1;
            }
        }
        if(maxOdd<maxEven) {
            return s.substr(evenId, maxEven);
        }
        return s.substr(oddId, maxOdd);
    }
};
