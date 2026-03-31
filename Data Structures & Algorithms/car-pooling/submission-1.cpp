class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> start, end;
        for(int i=0; i<trips.size(); i++) {
            start.push_back({trips[i][1], trips[i][0]});
            end.push_back({trips[i][2], trips[i][0]});
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i=0, j=0; 
        int curPass=0;
        while(i<start.size() && j<end.size()) {
            if(start[i].first<end[j].first) {
                curPass+=start[i].second; 
                if(curPass>capacity) {
                    return false;
                }
                i++;
            } else {
                curPass-=end[j].second; 
                j++;
            }
        }
        return true;
    }
};