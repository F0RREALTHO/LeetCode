class DisjointSet{
    public:
    vector<int> parent , rank;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i =0; i<n; i++) parent[i]=i;
    }

    int findUpar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_v == ulp_u) return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;

        DisjointSet ds(n);
        int cnt = n;
        for(auto &it:connections){
            if(ds.findUpar(it[0])!=ds.findUpar(it[1])){
                ds.UnionByRank(it[0],it[1]);
                cnt--;
            }
        }
        return cnt-1;
    }
};