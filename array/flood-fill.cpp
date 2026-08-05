class Solution {
public:

    void dfs(vector<vector<int>>& image,int x, int y, int originalColor, int newColor){
        int n= image.size();
        int m = image[0].size();

        if(x<0 || x>=n || y<0 || y>=m) return;
        if(image[x][y]!=originalColor) return;

        image[x][y] = newColor;

        dfs(image,x+1,y,originalColor,newColor);
        dfs(image,x,y+1,originalColor,newColor);
        dfs(image,x-1,y,originalColor,newColor);
        dfs(image,x,y-1,originalColor,newColor);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;
        dfs(image,sr,sc,originalColor,color);
        // int n = image.size();
        // int m = image[0].size();

        // // vector<vector<int>> vis(n, vector<int>(m, 0));
        // vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        // int originalColor = image[sr][sc];
        // if (originalColor == color) return image;
        // // vis[sr][sc] = 1;

        // queue<pair<int,int>> q;
        // q.push({sr,sc});
        // while(!q.empty()){
        //     auto[x,y] = q.front();
        //     q.pop();

        //     image[x][y]=color;

        //     for(auto [dx,dy]:dir){
        //         int nx = x+dx;
        //         int ny = y+dy;
        //         if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==originalColor 
        //         ){
        //             // vis[nx][ny] = 1;
        //             q.push({nx,ny});
        //         }
        //     }
        // }
        return image;
    }
};