class Solution {
public:
     int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] == 1 || grid[i][j] == 0)return 0;
        vis[i][j]=1;
        return 1+dfs(grid,i+1,j,vis)+dfs(grid,i-1,j,vis)+dfs(grid,i,j+1,vis)+dfs(grid,i,j-1,vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         if (grid.empty()) return 0;
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
        int maxi=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                   maxi=max(maxi,dfs(grid,i,j,vis));
                }
            }
        }
         return maxi;
    }
};
