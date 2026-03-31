class Solution {
private:
    vector<int> aux;
    unordered_map<int, unordered_map<int, int>> visited;
public:
    void buildHeap(vector<int>& nums) {
        int size=nums.size();
        for(int num : nums) {
            aux.push_back(num);
        }
        for(int i=floor((size-1)/2.0); i>=0; i--) {
            heapify(i);
        }
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
        swap(aux[minId], aux[id]);
        heapify(minId);
    }
    int pop() {
        int ans=aux[0];
        aux[0]=aux[size()-1];
        aux.pop_back();
        heapify(0);
        return ans;
    }
    bool isEmpty() {
        return aux.size()==0;
    }
    int size() {
        return aux.size();
    }
    void sort(vector<int>& nums) {
        int k=0;
        buildHeap(nums);
        while(!isEmpty()) {
            nums[k++]=pop();
        } 
    }
    bool isVisited(int i, int j, int k) {
        if(visited.find(i)!=visited.end() 
                && visited[i].find(j)!=visited[i].end()
                && visited[i][j]==k) {
            return true;
        }    
        visited[i][j]=k;
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums);
        int size=nums.size();
        unordered_map<int, int> count;
        for(int num : nums) {
            count[num]++;
        }
        vector<vector<int>> ans;
        int first, sec, third;
        for(int i=0; i<size; i++) {
            first=nums[i];
            for(int j=i+1; j<size; j++) {
                sec=nums[j];
                third=-(first+sec);
                count[first]--;
                count[sec]--;
                if(count[third]>0 && third>=sec) {
                    if(!isVisited(first, sec, third)) {
                        ans.push_back({first, sec, third});
                    }
                }   
                count[first]++;
                count[sec]++;
            }
        }
        return ans;
    }
};
