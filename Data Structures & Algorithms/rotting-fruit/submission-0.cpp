class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;  // Check for an empty grid

        int minutes = 0;
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;

        queue<pair<int, int>> rottenOranges;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    rottenOranges.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        vector<vector<int>> dir = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };

        while (!rottenOranges.empty() && freshOranges != 0) {
            int currentSize = rottenOranges.size();
            minutes++;
            while (currentSize-- && freshOranges != 0) {
                pair<int, int> topOrange = rottenOranges.front();
                rottenOranges.pop();
                
                for (const auto& d : dir) {
                    int idx = topOrange.first + d[0];
                    int idy = topOrange.second + d[1];
                    
                    if (idx >= 0 && idy >= 0 && idx < n && idy < m && grid[idx][idy] == 1) {
                        freshOranges--;
                        grid[idx][idy] = 2;
                        rottenOranges.push({idx, idy});
                    }
                }
            }
        }

        return freshOranges == 0 ? minutes : -1;
    }
};