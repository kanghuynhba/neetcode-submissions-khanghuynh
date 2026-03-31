class Solution {
private: 
    vector<int> aux;
public:
    int size() {
        return aux.size();
    }
    void buildHeap(vector<int>& nums) {
        aux=vector<int>(nums.size());
        for(int i=0; i<nums.size(); i++) {
            aux[i]=nums[i];
        }
        for(int i=floor((size()-1)/2.0); i>=0; i--) {
            heapify(i);
        }
    }
    int pop() {
        int ans=aux[0];
        aux[0]=aux[size()-1];
        aux.pop_back();
        heapify(0);
        return ans;
    }
    int leftChild(int id) {
        return 2*id+1;
    } 
    int rightChild(int id) {
        return 2*id+2;
    }
    void heapify(int id) {
        int minId=id;
        if(leftChild(id)<size() && aux[minId]>aux[leftChild(id)]) {
            minId=leftChild(id);
        }
        if(rightChild(id)<size() && aux[minId]>aux[rightChild(id)]) {
            minId=rightChild(id);
        }
        if(minId==id) {
            return;
        }
        swap(aux[id], aux[minId]);
        heapify(minId);
    }
    bool isEmpty() {
        return size()==0;
    }
    vector<int> sortArray(vector<int>& nums) {
        buildHeap(nums);
        int i=0;
        while(!isEmpty()) {
            nums[i++]=pop(); 
        }
        return nums;
    }
};
