class Solution {
public:
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int s, bool& ans) {
        if(!ans) {
            return;
        }
        visited[s]=true;
        for(int i=0; i<adjList[s].size(); i++) {
            int v=adjList[s][i];
            if(visited[v]) {
                ans=false;
                return;
            }
            if(!visited[v]) {
                dfs(adjList, visited, v, ans);
            }
        }
        visited[s]=false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);        
        int a, b;
        for(int i=0; i<prerequisites.size(); i++) {
            a=prerequisites[i][0];
            b=prerequisites[i][1];
            adjList[b].push_back(a);
        }
        vector<bool> visited(numCourses, false);
        bool ans=true;
        for(int i=0; i<numCourses; i++) {
            if(visited[i]==0) {
                dfs(adjList, visited, i, ans);
                if(!ans) {
                    return false;
                }
            }
        }
        return ans;
    }
};

