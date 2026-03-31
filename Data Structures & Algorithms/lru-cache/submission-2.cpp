class LRUCache {
    queue<pair<int, int>> q;
    unordered_map<int, int> map, recently_used;
    int timestamp=0, cap;
public:
    LRUCache(int capacity) {
        cap=capacity; 
    }
    
    int get(int key) {
        if(map.find(key)!=map.end()) {
            q.push({key, timestamp});
            recently_used[key]=timestamp++;
            return map[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        int curTimestamp;
        pair<int, int> front;
        if(map.find(key)==map.end() && map.size()==cap) {
            while(!q.empty()) {
                front=q.front();
                q.pop();
                curTimestamp=recently_used[front.first];
                if(curTimestamp==front.second) {
                    map.erase(front.first);
                    break;
                }
            }
        } 
        map[key]=value;
        q.push({key, timestamp});
        recently_used[key]=timestamp++;
    }
};