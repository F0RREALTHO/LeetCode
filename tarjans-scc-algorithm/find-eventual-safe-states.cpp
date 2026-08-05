class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<int> & pathVis, 
    vector<vector<int>>& graph, vector<bool> &check){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto edges:graph[node]){
            if(!vis[edges]){
                if(dfs(edges,vis,pathVis,graph,check)) return true;
            }
            else if(pathVis[edges]) return true;
        }
        pathVis[node] = 0;
        check[node] = true;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<bool> check(V,false);

        for(int i = 0 ; i<V;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,graph,check);
            }
        }

        vector<int> safeNode;
        for(int i=0; i<V;i++){
            if(check[i]) safeNode.push_back(i);
        }

        return safeNode;
    }
};