class Solution {
public:
    void increment(vector<int>& count, char c) {
        if(c<='Z') {
            count[c-'A']++;
        } else {
            count[25+(c-'a')]++;
        }
    }
    void decrement(vector<int>& count, char c) {
        if(c<='Z') {
            count[c-'A']--;
        } else {
            count[25+(c-'a')]--;
        }
    }
    bool check(vector<int>& sCount, vector<int>& tCount) {
        for(int i=0; i<sCount.size(); i++) {
            if(sCount[i]<tCount[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size()<t.size()) {
            return "";
        }
        vector<int> countT(52, 0);         
        int tSize=t.size();
        for(int i=0; i<tSize; i++) {
            increment(countT, t[i]); 
        }
        vector<int> count(52, 0);
        for(int i=0; i<tSize; i++) {
            increment(count, s[i]);
        }
        int i=tSize-1, j=0;
        string ans=""; 
        int minLength=INT_MAX;
        int minJ=-1;
        while(i-j+1>=tSize && i<s.size()) {
            if(check(count, countT)) {
                if(minLength>i-j+1) {
                    minLength=i-j+1;
                    minJ=j;
                }
                decrement(count, s[j++]);
            } else {
                increment(count, s[++i]);
            } 
        }
        if(minJ==-1) {
            return "";
        }
        return s.substr(minJ, minLength);
    }
};

/*
 *  s="OUZODYXAZV" t="XYZ"
 *  
 * */
