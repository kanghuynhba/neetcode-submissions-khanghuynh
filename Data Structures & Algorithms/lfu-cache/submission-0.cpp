class Node {
public:
    int key, val, count;
    Node *prev, *next;

    Node(int k, int v, int c): key(k), val(v), count(c), prev(NULL), next(NULL) {}
};

class LFUCache {
private:
    int cap, size;
    unordered_map<int, Node*> cache;
    vector<pair<Node*, Node*>> level;
public:
    void push(Node* node) {
        if(level.size()==node->count) {
            Node* head=new Node(-1, -1, -1);
            Node* tail=new Node(-1, -1, -1);
            head->next=tail;
            tail->prev=head;
            level.push_back({head, tail});            
        }
        Node* curHead=level[node->count].first; 
        curHead->next->prev=node;
        node->next=curHead->next;
        node->prev=curHead;
        curHead->next=node;
        cache[node->key]=node;
        size++;
    }

    void remove(Node* node) {
        node->prev->next=node->next;
        node->next->prev=node->prev;
        cache.erase(node->key);
        delete node;
        size--;
    }

    bool checkEmpty(pair<Node*, Node*> curLevel) {
        if(curLevel.first->next==curLevel.second) {
            return true;
        }
        return false;
    }
    
    LFUCache(int capacity) {
        cap=capacity;        
        size=0;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) {
            return -1;
        }
        Node* curNode=cache[key];
        Node* newNode=new Node(curNode->key, curNode->val, curNode->count+1);
        remove(curNode);
        push(newNode);
        return newNode->val;
    }
    
    void put(int key, int value) {
        int count=0;
        if(cache.find(key)!=cache.end()) {
            count=cache[key]->count+1;
            remove(cache[key]);
        } else if(cap==size) {
            Node* curNode;
            for(int i=0; i<level.size(); i++) {
                if(!checkEmpty(level[i])) {
                    curNode=level[i].second->prev;
                    break;
                }
            }                  
            cache.erase(curNode->key);
            remove(curNode);
        }
        Node *node=new Node(key, value, count);
        push(node);
    }
};

