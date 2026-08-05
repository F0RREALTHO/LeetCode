class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,1e8));

        for (int i = 0; i < n; i++) adj[i][i] = 0;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u][v]=w; adj[v][u]=w;
        }

        for(int via = 0; via<n; via++){
            for(int i =0; i<n;i++){
                for(int j =0; j<n; j++){
                    if(adj[i][via]!=1e8 && adj[via][j]!=1e8){
                        adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
                    }
                }
            }
        }
        int minReach = INT_MAX, city = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0; j<n;j++){
                if(adj[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<=minReach){
                minReach = cnt;
                city = i;
            }
        }

        return city;
    }
};