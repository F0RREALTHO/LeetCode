class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_v == ulp_u)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        for(int i = 0; i<n; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j]==1){
                    int id = n*i+j;
                    for(auto [dx,dy]:dir){
                        int nx = i+dx;
                        int ny = j+dy;
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1){
                            int nid = n*nx+ny;
                            ds.UnionByRank(id,nid);;
                        }
                    }
                }
            }
        }

        vector<int> sizes(n * n, 0);
        for(int i= 0; i<n*n; i++){
            if(grid[i/n][i%n]==1){
                int root = ds.findUpar(i);
                sizes[root]++;
            }
        }

        int maxi = 0;
        for (int i = 0; i < n * n; i++) {
            if (grid[i / n][i % n] == 1) {
                maxi = max(maxi, sizes[ds.findUpar(i)]);
            }
        }

        for(int i = 0; i<n ;i++){
            for(int j =0;j<n; j++){
                if(grid[i][j]==0){
                    unordered_set<int> seen;
                    int cnt = 1;
                    for(auto [dx,dy]:dir){
                        int nx = i+dx;
                        int ny = j+dy;
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1){
                            int comp = ds.findUpar(nx*n+ny);
                            if(!seen.count(comp)){
                                cnt+=sizes[comp];
                                seen.insert(comp);
                            }
                        }
                    }
                    maxi = max(maxi,cnt);
                }
            }
        }
        return (maxi == 0? n*n:maxi);
    }
};