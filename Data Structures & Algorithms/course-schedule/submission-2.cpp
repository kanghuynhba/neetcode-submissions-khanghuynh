class Solution {
public:
    bool dfs(vector<vector<int>>& adjList, vector<bool>& visited, int s) {
        visited[s]=true;
        for(int i=0; i<adjList[s].size(); i++) {
            int v=adjList[s][i];
            if(visited[v]) {
                return false;
            }
            if(!visited[v] && !dfs(adjList, visited, v)) {
                return false;
            }
        }
        visited[s]=false;
        return true;
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
        for(int i=0; i<numCourses; i++) {
            if(visited[i]==0) {
                if(!dfs(adjList, visited, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};

