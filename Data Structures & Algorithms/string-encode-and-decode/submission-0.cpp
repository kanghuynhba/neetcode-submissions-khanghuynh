class Solution {
private:
    unordered_map<int, string> hash;
    unordered_map<string, char> unhash;
public:
    string itoa(int i) {
        if(i==0) {
            return "";
        }
        return itoa(i/10)+(char)('0'+i%10);
    }

    string addZero(string s) {
        string t="000";
        int lastId=t.size()-1;
        for(int i=s.size()-1; i>=0; i--) {
            t[lastId--]=s[i];
        }
        return t;
    }

    string hashFunc(string s) {
        string t="";
        int k;
        for(int i=0; i<s.size(); i++) {
            k=s[i];
            t+=hash[k];
        }    
        return t;
    }

    string unhashFunc(string s) {
        string t="";
        for(int i=0; i<s.size(); i+=3) {
            t+=unhash[s.substr(i, 3)]; 
            cout << t << " ";
        }
        return t;
    }

    string encode(vector<string>& strs) {
        string s="";
        for(int i=1; i<=256; i++) {
            hash[i]=addZero(itoa(i));
            unhash[addZero(itoa(i))]=(char)(i);
        }
        for(string str : strs) {
            s+=hashFunc(str);
            s+=" ";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int begin=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]==' ') { 
                ans.push_back(unhashFunc(s.substr(begin, i-begin)));
                begin=i+1; 
            } 
        }
        return ans;
    }
};
