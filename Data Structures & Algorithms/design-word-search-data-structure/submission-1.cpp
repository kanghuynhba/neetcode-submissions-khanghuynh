class WordDictionary {
public:
    struct Node {
        Node* child[26];
        int wordCount=0;
    };

    struct Trie {
        Node* root;
    };

    Node* createNode() {
        Node* newNode=new Node();
        for(int i=0; i<25; i++) {
            newNode->child[i]=NULL;
        }
        return newNode;
    }

    Trie* buildTrie() {
        Trie* trie=new Trie(); 
        trie->root=createNode();
        return trie;
    }

    Trie* trie;

    void prefixTree() {
        trie=buildTrie(); 
    }
 
    WordDictionary() {
        prefixTree();
    }
    
    void addWord(string word) {
        int ch;
        Node* root=trie->root;
        for(int i=0; i<word.size(); i++) {
            ch=word[i]-'a';
            if(root->child[ch]==NULL) {
                root->child[ch]=createNode();
            }
            root=root->child[ch];
        }
        root->wordCount=1;
    }

    void dfsSearch(Node* root, string& word, int id, bool& flag) {
        if(id==word.size() && root->wordCount>=1) {
            if(root->wordCount>=1) {
                flag=true;
            }
            return;
        } 
        if(word[id]=='.') {
            for(int i=0; i<26; i++) {
                if(root->child[i]) {
                    dfsSearch(root->child[i], word, id+1, flag);
                }            
            }
            if(flag) {
                return;
            }
        } else {
            int ch=word[id]-'a';
            if(root->child[ch]) {
                dfsSearch(root->child[ch], word, id+1, flag);
            } else {
                return;
            }
        }
    }
    
    bool search(string word) {
        bool ans=false;
        dfsSearch(trie->root, word, 0, ans);        
        return ans;
    }
};
