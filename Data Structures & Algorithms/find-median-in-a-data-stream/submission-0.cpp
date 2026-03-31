class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        bool flag=true;
        if(!minHeap.empty() && num>minHeap.top()) {
            flag=false;
            minHeap.push(num);
        } 
        if(!maxHeap.empty() && num<maxHeap.top()) {
            flag=false;
            maxHeap.push(num);
        }
        if(flag) {
            minHeap.push(num);
        }
        int minHeapSize=minHeap.size();
        int maxHeapSize=maxHeap.size();
        if(minHeapSize-maxHeapSize>1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeapSize-minHeapSize>1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()) {
            return (double)(minHeap.top()+maxHeap.top())/2.0;
        } 
        if(minHeap.size()>maxHeap.size()) {
            return minHeap.top();
        }
        return maxHeap.top();
    }
};
