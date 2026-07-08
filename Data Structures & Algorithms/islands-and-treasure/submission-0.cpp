class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();
                int r = it.first.first;
                int c = it.first.second;
                int dist = it.second;
                for (auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == INT_MAX) {
                       grid[nr][nc]=dist+1;
                       q.push({{nr,nc},dist+1});
                    }
                }
            }
        }
        return;
    }
};