class Solution {
public:  int numDecodings(string s) {
    if(s[0]=='0') {
        return 0;
    }
    int first=1, sec=1;
    int size=s.size();
    int temp;
    for(int i=1; i<size; i++) {
        temp = sec;
        if(s[i] == '0') {
            if(s[i-1] == '1' || s[i-1] == '2') {
                sec = first;
            } else {
                return 0;
            }
        } else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
            sec += first;
        } 
        first = temp;
    }
    return sec;
}
};