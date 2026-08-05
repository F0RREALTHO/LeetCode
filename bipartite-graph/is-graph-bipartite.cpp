class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);

        for(int i=0;i<n;i++){
            if(col[i]!=-1) continue;
            queue<int> q;
            q.push(i);
            col[i]=0;
            while(!q.empty()){
                int top = q.front();
                q.pop();
                bool color = col[top];
                for(auto node: graph[top]){
                    if(col[node]==-1) {
                        q.push(node);
                        if(color) col[node] = 0;
                        else col[node] = 1;
                    }
                    if(col[node]==col[top]) return false;
                }
            }
        }
        return true;
    }
};