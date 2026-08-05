class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& flg, int node){
        if(flg[node]) return;
        flg[node] = true;

        for(auto u: adj[node]){
            if(!flg[u]) dfs(adj,flg,u);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        int m = invocations.size();
        for(int i=0; i<m; i++){
            int u = invocations[i][0], v= invocations[i][1];
            adj[u].push_back(v);
        }
        vector<bool> flg(n,false);
        dfs(adj,flg,k);

        vector<int> ans;

        for(int i =0; i<m; i++){
            int u = invocations[i][0], v = invocations[i][1];
            if(!flg[u] && flg[v]){
                for(int i=0; i<n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        for(int i=0; i<n; i++){
            if(!flg[i]) ans.push_back(i);
        }
        
        return ans;
    }
};