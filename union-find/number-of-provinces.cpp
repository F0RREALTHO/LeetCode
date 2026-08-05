class Solution {
public:

    void dfs(int node,vector<vector<int>>& isConnected, vector<bool> &vis){
        vis[node]=true;
        int n = isConnected.size();
        for(int i =0; i<n;i++){
            if(isConnected[node][i]&& !vis[i]) dfs(i,isConnected,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,isConnected,vis);
            }
        }
        return cnt;
    }
};