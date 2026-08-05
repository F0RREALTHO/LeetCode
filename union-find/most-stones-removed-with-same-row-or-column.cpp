class DisjointSet{
    public:
    vector<int> parent , rank;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i =0; i<=n; i++) parent[i]=i;
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> mp;
        for(auto it:stones){
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;
            ds.UnionByRank(rowNode,colNode);
            mp[rowNode] = 1;
            mp[colNode ]= 1;
        }

        int cnt = 0;
        for(auto it:mp){
            if(ds.findUpar(it.first) == it.first) cnt++;
        }

        return stones.size()-cnt;
    }
};