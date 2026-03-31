class Solution {
private:
    const int dr[4]={0, -1, 0, 1};
    const int dc[4]={-1, 0, 1, 0};
    int M, N;
public:
    bool isValid(int x, int y) {
        return x>=0 && y>=0 && x<M && y<N;
    }
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, string& word, 
            int x, int y, int k, bool& flag) {
        if(k==word.size()) {
            flag=true;
            return;
        }
        visited[x][y]=1;
        for(int i=0; i<4; i++) {
            int r=dr[i];
            int c=dc[i];
            if(isValid(x+r, y+c) 
                    && visited[x+r][y+c]!=1 
                    && board[x+r][y+c]==word[k]) {
                dfs(board, visited, word, x+r, y+c, k+1, flag);
            }
        }
        visited[x][y]=2;
    }
    bool exist(vector<vector<char>>& board, string word) {
        M=board.size(); // #rows
        N=board[0].size(); // #cols
        bool ans=false;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j]==word[0]) {
                    vector<vector<int>> visited(M, vector<int>(N, 0));
                    ans=false;
                    dfs(board, visited, word, i, j, 1, ans);
                    if(ans) {
                        return ans; 
                    }
                }
                
            }
        }
        return ans;
    }
};

