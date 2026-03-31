
class LRUCache {
private:
    unordered_map<int, int> db;
    unordered_map<int, int> lastestTime;
    queue<pair<int, int>> history;
    int capacity;
    int count;
    int timeStamp;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->count=0;
        this->timeStamp=0;
    }
    
    int get(int key) {
        if(db.find(key)==db.end()) {
            return -1;
        }     
        this->history.push({key, this->timeStamp});
        this->lastestTime[key]=this->timeStamp++;
        return db[key];
    }
    /*
    ["LRUCache", [2], "get", [2], "put", [2, 6], "get", [1], "put", [1, 5], "put", [1, 2], "get", [1], "get", [2]]
    capacity=2
    G 2 -> -1
    P 2,6 -> q[{2,0}]
             lastestTime[2]=0, db[2]=6
    G 1 -> -1
    P 1,5 -> q[{2,0},{1,1}]
             lastestTime[2]=0, db[2]=6
             lastestTime[1]=1, db[1]=5
    P 1,2 -> q[{2,0},{1,1},{1,2}]
              lastestTime[2]=0, db[2]=6
              lastestTime[1]=2, db[1]=2
    G 1 -> 2 q[{2,0},{1,1},{1,2},{1,3}]
              lastestTime[2]=0, db[2]=6
              lastestTime[1]=3, db[1]=2
    */
    void put(int key, int value) {
        if(db.find(key)==db.end()) {
            this->count++;
        }
        while(this->count>this->capacity) {
            int leastUsedKey=this->history.front().first; 
            int leastUsedTimeStamp=this->history.front().second; 
            if(this->lastestTime[leastUsedKey]==leastUsedTimeStamp) {
                this->count--;
                this->db.erase(leastUsedKey);
            }
            this->history.pop();
        } 
        this->db[key]=value;
        this->lastestTime[key]=this->timeStamp;
        this->history.push({key, this->timeStamp++});
    }
};