class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] == 1 || grid[i][j] == '0')return;
        vis[i][j]=1;
        dfs(grid,i+1,j,vis);
        dfs(grid,i-1,j,vis);
        dfs(grid,i,j+1,vis);
        dfs(grid,i,j-1,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
        int no=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                   no++;
                   dfs(grid,i,j,vis);
                }
            }
        }
         return no;
    }
};