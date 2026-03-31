class Solution {
private:
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};
    int m, n;
    vector<vector<bool>> atlantic, pacific;
public:
    bool isValid(int r, int c) {
        return r<m && c<n && r>=0 && c>=0;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c]=true;
        for(int i=0; i<4; i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isValid(nr, nc) && !visited[nr][nc] && heights[r][c]<=heights[nr][nc]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(), n=heights[0].size();
        pacific=vector<vector<bool>>(m, vector<bool>(n, false));
        atlantic=vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            if(!pacific[i][0]) {
                dfs(heights, pacific, i, 0);
            }
            if(!atlantic[i][n-1]) {
                dfs(heights, atlantic, i, n-1);
            }
        }
        for(int i=0; i<n; i++) {
            if(!pacific[0][i]) {
                dfs(heights, pacific, 0, i);
            }
            if(!atlantic[m-1][i]) {
                dfs(heights, atlantic, m-1, i);
            }
        }
        dfs(heights, atlantic, m-1, n-1);
        vector<vector<int>> ans;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
