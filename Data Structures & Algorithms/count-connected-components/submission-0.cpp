class Solution {
private: 
    int N;
    vector<vector<int>> adjList;
    vector<bool> visited;
public:
    void dfs(int s) {
        visited[s]=true;
        for(int i=0; i<adjList[s].size(); i++) {
            int v=adjList[s][i];
            if(!visited[v]) {
                dfs(v);
            } 
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n==1) {
            if(edges.size()==0) {
                return true;
            }
            return false;
        }
        N=n;
        adjList=vector<vector<int>>(N);
        visited=vector<bool>(N, false);
        int u, v;
        for(int i=0; i<edges.size(); i++) {
            u=edges[i][0];
            v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        int count=0;
        for(int i=0; i<N; i++) {
            if(!visited[i]) {
                dfs(i);
                count++;
            }       
        }
        return count;
    }
};
