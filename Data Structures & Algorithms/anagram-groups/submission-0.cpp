class Solution {
public:
    string itoa(int a) {
        if(a==0) {
            return "";
        }        
        return itoa(a/10)+(char)('0'+a%10);
    }
    string hash(string s) {
        vector<int> c(26, 0);        
        string h="";
        for(int i=0; i<s.size(); i++) {
            c[s[i]-'a']++;
        }
        for(int i=0; i<26; i++) {
            h+=itoa(c[i])+",";
        } 
        return h;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> ans;
        string h;
        int id=0;
        for(int i=0; i<strs.size(); i++) {
            h=hash(strs[i]);
            if(map.find(h)!=map.end()) {
                ans[map[h]].push_back(strs[i]);
            } else {
                map[h]=id++;
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};

