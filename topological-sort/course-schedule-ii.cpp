class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto x:prerequisites) adj[x[1]].push_back(x[0]);
        vector<int> in(n,0);
        for(int i = 0; i<n; i++) for(auto x:adj[i]) in[x]++;
        queue<int> q;
        for(int i = 0; i<n; i++) if(!in[i]) q.push(i);
        vector<int> a;
        while(q.size()){
            int node = q.front();
            q.pop();
            a.push_back(node);
            for(auto x: adj[node]){
                in[x]--;
                if(!in[x]) q.push(x);
            }
        }
        vector<int> b = {};
        if(a.size()==n){
            return a;
        }else{
            return b;
        }
    }
};