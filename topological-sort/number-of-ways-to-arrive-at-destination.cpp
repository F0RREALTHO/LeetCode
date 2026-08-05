class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        vector<vector<pair<long long,int>>> adj(n);
        for(auto &edge:roads){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long> ti(n,LLONG_MAX);
        ti[0]=0;
        set<pair<long long,int>> s;
        s.insert({0,0});
        vector<int> cnt(n,0);
        cnt[0]=1;

        while(!s.empty()){
            auto it = *s.begin();
            long long wt = it.first;
            int node= it.second;
            s.erase(it);

            if(wt>ti[node]) continue;

            for(auto &[nei,cost]:adj[node]){
                if(cost+wt<ti[nei]){
                    s.erase({ti[nei],nei});
                    ti[nei]= cost+wt;
                    cnt[nei]=cnt[node];
                    s.insert({ti[nei],nei});
                }
                else if(cost+wt==ti[nei]){
                    cnt[nei]=(cnt[nei]+cnt[node])%MOD;
                }
            }
        }
        return cnt[n-1] % MOD;

    }
};