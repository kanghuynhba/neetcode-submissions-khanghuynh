class Solution {
public:
    void dijkstra(int s, vector<vector<pair<int, int>>>& adjList, vector<int>& dist) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[s]=0;
        pq.push({ dist[s], s}); 
        while(!pq.empty()) {
            int currNode=pq.top().second;
            pq.pop();
            for(int i=0; i<adjList[currNode].size(); i++) {
                int neighborNode=adjList[currNode][i].first;
                int weight=adjList[currNode][i].second;
                if(dist[currNode]+weight<dist[neighborNode]) {
                    dist[neighborNode]=dist[currNode]+weight;
                    pq.push({dist[neighborNode], neighborNode});
                }
            }    
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for(int i=0; i<times.size(); i++) {
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int w=times[i][2];
            adjList[u].push_back({v, w});
        }
        vector<int> dist(n, INT_MAX);
        dijkstra(k-1, adjList, dist);
        int maxWeight=0;
        for(int i=0; i<n; i++) {
            if(dist[i]==INT_MAX) {
                return -1;
            }
            maxWeight=max(maxWeight, dist[i]);
        }
        return maxWeight;
    }
};