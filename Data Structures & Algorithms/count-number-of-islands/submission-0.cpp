class Solution {
private:
    int M, N;
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};
    vector<vector<bool>> visited;
public:
    bool isValid(int r, int c) {
        return r>=0 && c>=0 && r<M && c<N;
    }
    void bfs(vector<vector<char>>& grid, int i, int j) {
        visited[i][j]=true;
        queue<pair<int, int>> q;
        q.push({i, j});
        int r, c, nr, nc;
        while(!q.empty()) {
            r=q.front().first;
            c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                nr=r+dr[i];
                nc=c+dc[i];
                if(isValid(nr, nc) && !visited[nr][nc] && grid[nr][nc]=='1') {
                    q.push({nr, nc});
                    visited[nr][nc]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        M=grid.size(), N=grid[0].size();
        visited=vector<vector<bool>>(M, vector<bool>(N, false));
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j]=='1' && !visited[i][j]) {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
