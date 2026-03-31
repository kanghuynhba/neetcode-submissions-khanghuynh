class Solution {
private: 
    int N;
    vector<vector<int>> adjList;
    vector<int> visited;
public:
    void dfs(int s, bool& flag) {
        if(flag) {
            return;
        }
        visited[s]=1;
        for(int i=0; i<adjList[s].size(); i++) {
            int v=adjList[s][i];
            if(visited[v]==0) {
                dfs(v, flag);
            } else if(visited[v]==2) {
                flag=true; 
                return;
            }
        }
        visited[s]=2;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==1) {
            if(edges.size()==0) {
                return true;
            }
            return false;
        }
        N=n;
        adjList=vector<vector<int>>(N);
        visited=vector<int>(N, 0);
        int u, v;
        for(int i=0; i<edges.size(); i++) {
            u=edges[i][0];
            v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        bool flag=false;
        dfs(0, flag);
        for(int i=0; i<N; i++) {
            if(visited[i]==0) {
                return false;
            }       
        }
        return !flag;
    }
};
