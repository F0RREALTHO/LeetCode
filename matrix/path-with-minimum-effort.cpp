class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> eff(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        eff[0][0] = 0;
        while(!pq.empty()){
            auto [dif,pos] = pq.top();
            auto [x,y] = pos;
            pq.pop();
            if(x == n-1 && y == m-1) return dif;
            for(auto [dx,dy]:dir){
                int nx = x+dx;
                int ny = y+dy;
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int st = abs(heights[nx][ny]-heights[x][y]);
                    int newst = max(st,dif);
                    if(newst<eff[nx][ny]){
                        eff[nx][ny] = newst;
                        pq.push({newst,{nx,ny}});
                    }
                }
            }
        }
        return eff[n-1][m-1];
    }
};