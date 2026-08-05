class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<pair<int,int>> di = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        pq.push({1,{0,0}});
        dist[0][0]=1;
        while(!pq.empty()){
            auto [d, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();

            if(x == n-1 && y == n-1) return d;
            for(auto [dx,dy]:di){
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    if(d+1<dist[nx][ny]){
                        dist[nx][ny] = d + 1;
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return -1;
    }
};