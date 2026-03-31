
class Node {
public:
    int key, val;
    Node *prev, *next;

    Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int cap, size;
    Node *head, *tail;
    unordered_map<int, Node*> cache;
public:
    void push(Node* node) {
        if(size==0) {
            head=node;
            tail=node;
        } else {
            node->next=head;
            head->prev=node;
            head=node;
        }
        size++;
    }

    void remove(Node* node) {
        if(node==tail) {
            tail=tail->prev;
        }
        if(node==head) {
            head=head->next;
        }
        if(node->prev) {
            node->prev->next=node->next;
        }
        if(node->next) {
            node->next->prev=node->prev;
        }
        delete node;
        size--;
    }

    LRUCache(int capacity) {
        cap=capacity; 
        size=0;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) {
            return -1;
        } 
        Node* node= new Node(key, cache[key]->val);
        remove(cache[key]);
        cache[key]=node;
        push(node);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()) {
            remove(cache[key]);
            cache.erase(key);
        } else if(size==cap) {
            cache.erase(tail->key);
            remove(tail);
        }
        Node *node= new Node(key, value);
        cache[key]=node;
        push(node);
    }
};