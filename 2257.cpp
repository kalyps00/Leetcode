#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        // znaczniki: 0 = empty, 1 = guarded, 2 = guard or wall
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (const auto &v : walls)
        {
            grid[v[0]][v[1]] = 2;
        }
        for (const auto &v : guards)
        {
            grid[v[0]][v[1]] = 2;
        }
        // up, down, left, right
        int dir_row[] = {-1, 1, 0, 0};
        int dir_col[] = {0, 0, -1, 1};
        for (const auto &v : guards)
        {
            int row = v[0], col = v[1];
            for (int d = 0; d < 4; d++)
            {
                int r = row + dir_row[d];
                int c = col + dir_col[d];
                while (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 2)
                {
                    grid[r][c] = 1;
                    r += dir_row[d];
                    c += dir_col[d];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    ++ans;
        return ans;
    }
};