class Solution
{
  public:
    bool satisfiesConditions(vector<vector<int>> &grid)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            int curr = grid[0][j];

            for (int i = 1; i < grid.size(); i++)
            {
                if (grid[i][j] != curr)
                {
                    return false;
                }
            }

            if (j != grid[0].size() - 1 && curr == grid[0][j + 1])
            {
                return false;
            }
        }

        return true;
    }
};