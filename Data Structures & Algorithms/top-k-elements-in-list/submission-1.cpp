class Solution {
private:
    vector<pair<int, int>> aux;
public:
    int size() {
        return aux.size();
    }
    void buildHeap(vector<int>& count) {
        for(int i=0; i<count.size(); i++) {
            aux.push_back({count[i], i});
        }
        for(int i=floor((size()-1)/2.0); i>=0; i--) {
            heapify(i);
        }
    }
    pair<int, int> pop() {
        pair<int, int> ans=aux[0];
        aux[0]=aux[size()-1];
        aux.pop_back();
        heapify(0);
        return ans;
    }
    int leftChild(int i) {
        return 2*i+1;
    }
    int rightChild(int i) {
        return 2*i+2;
    }
    void heapify(int id) {
        int maxId=id;
        if(leftChild(id)<size() && aux[maxId].first<aux[leftChild(id)].first) {
            maxId=leftChild(id);
        }
        if(rightChild(id)<size() && aux[maxId].first<aux[rightChild(id)].first) {
            maxId=rightChild(id);
        }
        if(maxId==id) {
            return;
        }
        swap(aux[id], aux[maxId]);
        heapify(maxId);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> count(2001, 0);
        for(int num : nums) {
            count[num+1000]++;
        }
        buildHeap(count);
        vector<int> ans(k);
        int i=0;
        while(k>0) {
            k--;
            ans[i++]=pop().second-1000;
        }
        return ans;
    }
};
