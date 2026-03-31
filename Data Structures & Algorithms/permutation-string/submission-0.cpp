

class Solution {
private:
    const int NUMB_OF_CHAR=26;
public:
    bool isEqual(vector<int>& a, vector<int>& b) {
        for(int i=0; i<NUMB_OF_CHAR; i++) {
            if(a[i]!=b[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> count(NUMB_OF_CHAR, 0);
        vector<int> check(NUMB_OF_CHAR, 0);
        int ch;
        for(int i=0; i<s1.size(); i++) {
            ch=s1[i]-'a';
            count[ch]++;
        }
        int l=0, r=s1.size()-1;
        for(int i=l; i<=r; i++) {
            ch=s2[i]-'a';
            check[ch]++;
        }
        while(r<s2.size()) {
            if(isEqual(count, check)) {
                return true;
            }
            check[s2[l++]-'a']--; 
            check[s2[++r]-'a']++; 
        }
        return false;
    }
};