class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> start, end;
        vector<int> lastId(26, 0);
        int ch, size=s.size();
        for(int i=0; i<size; i++) {
            ch=s[i]-'a';
            lastId[ch]=i;
        }        
        vector<int> ans;
        int firstId=0;
        int i=0, j;
        while(i<size) {
            ch=s[i]-'a';
            firstId=i;
            j=lastId[ch];
            while(i<=j) {
                ch=s[i++]-'a';
                j=max(j, lastId[ch]);
            }
            ans.push_back(i-firstId);
        }
        return ans;
    }
};

/*
    how should you express your idea?
        through an example 
             012345
            "abcabc"
                        i j
                        0 3 
                        1 4                
                        2 5

            "abacd"     i j
                        0 2
                        1 2
                        2 2

*/
