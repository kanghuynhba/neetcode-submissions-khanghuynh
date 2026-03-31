class Solution {
private:
    struct Node {
        Node* child[26];
        int wordId;
    };
    Node* root;
    int M, N;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
public:
    Node* createNode() {
        Node* newNode=new Node();
        for(int i=0; i<26; i++) {
            newNode->child[i]=NULL;
        }
        newNode->wordId=-1;
        return newNode;
    }
    bool isValid(int x, int y) {
        return x>=0 && y>=0 && x<M && y<N;
    }
    void dfs(vector<bool>& ans, Node* node, vector<vector<char>>& board, 
            vector<vector<bool>>& visited, int r, int c) {
        visited[r][c]=true; 
        if(node->wordId!=-1) {
            ans[node->wordId]=true;
        }
        for(int i=0; i<4; i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isValid(nr, nc) && !visited[nr][nc]) {
                int ch=board[nr][nc]-'a';
               if(node->child[ch]) {
                    dfs(ans, node->child[ch], board, visited, nr, nc);
                }
            }
        }
        visited[r][c]=false;
    }
    void insertWord(Node* node, string word, int id) {
        int ch;
        for(int i=0; i<word.size(); i++) {
            ch=word[i]-'a';
            if(node->child[ch]==NULL) {
                node->child[ch]=createNode();
            }
            node=node->child[ch];
        }
        node->wordId=id;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        M=board.size(), N=board[0].size();
        root=createNode();  
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        for(int i=0; i<words.size(); i++) {
            insertWord(root, words[i], i);
        }
        int ch;
        vector<string> ans;
        vector<bool> markWord(words.size(), false);
        for(int i=0; i<26; i++) {
            if(root->child[i]) {
                Node* node=root->child[i];
                for(int j=0; j<M; j++) {
                    for(int k=0; k<N; k++) {
                        ch=board[j][k]-'a';
                        if(i==ch) {
                            dfs(markWord, node, board, visited, j, k);
                        }
                    }
                }
            }
        }
        for(int i=0; i<words.size(); i++) {
            if(markWord[i]) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};

