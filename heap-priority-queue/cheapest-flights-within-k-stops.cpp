class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:flights){
            int u = e[0]; int v = e[1]; int w = e[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][k+1]=0;
        pq.push({0,{src,k+1}});

        while(!pq.empty()){
            auto [price,data] = pq.top();
            auto [from,stops] = data;
            pq.pop();
            if(from == dst) return price;
            if(stops>0){
                for(auto &[to,cost]:adj[from]){
                    if(price+cost<dist[to][stops-1]){
                        dist[to][stops-1] = price+cost;
                        pq.push({price+cost,{to,stops-1}});
                    }
                }
            }
        }
        return -1;
    }
};