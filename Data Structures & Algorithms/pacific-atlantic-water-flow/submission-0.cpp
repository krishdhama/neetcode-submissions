class Solution {
   public:
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& ocean, vector<pair<int, int>>& dir) {
        ocean[i][j] = 1;
        for(auto it:dir){
            int nr=i+it.first;
            int nc=j+it.second;
            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && ocean[nr][nc]==0 && heights[nr][nc]>=heights[i][j]){
                dfs(heights,nr,nc,ocean,dir);
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    if (pacific[i][j] == 0) dfs(heights, i, j, pacific, dir);
                }
                if (i == n - 1 || j == m - 1) {
                    if (atlantic[i][j] == 0) dfs(heights, i, j, atlantic, dir);
                }
            }
        }
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1) result.push_back({i, j});
            }
        }
        return result;
    }
};