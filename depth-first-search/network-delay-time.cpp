class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
        vector<int> ti(n+1,1e9);
        ti[k]=0,ti[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto [t,node] = pq.top();
            pq.pop();
            if(t>ti[node]) continue;
            for(auto [nei,cost]:adj[node]){
                if(t+cost<ti[nei]){
                    ti[nei]=t+cost;
                    pq.push({ti[nei],nei});
                }
            }
        }
        int ans = 0;
        for(int i =1; i<n+1;i++){
            if (ti[i] == 1e9) return -1;
            ans = max(ans, ti[i]);
        }

        return ans;
    }
};