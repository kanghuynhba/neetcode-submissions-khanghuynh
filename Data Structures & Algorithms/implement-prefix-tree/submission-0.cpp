class PrefixTree {
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

    PrefixTree() {
        trie=buildTrie(); 
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        int ch;
        Node* root=trie->root;
        for(int i=0; i<word.size(); i++) {
            ch=word[i]-'a';
            if(root->child[ch]==NULL) {
                return false;
            }
            root=root->child[ch];
        }
        return root->wordCount>=1;
    }
    
    bool startsWith(string prefix) {
        int ch;
        Node* root=trie->root;
        for(int i=0; i<prefix.size(); i++) {
            ch=prefix[i]-'a'; 
            if(root->child[ch]==NULL) {
                return false;
            }
            root=root->child[ch];
        }
        return true;
    }
};

