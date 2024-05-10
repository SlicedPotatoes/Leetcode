class Solution
{
  public:
    bool canMakeSquare(vector<vector<char>> &grid)
    {
        // Parcourir le coin haut / gauche de chaque carré de 2x2
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                // Compter le nombre de caractères identiques adjacents
                int countSame = 1;

                countSame += grid[i][j] == grid[i][j + 1];
                countSame += grid[i][j] == grid[i + 1][j];
                countSame += grid[i][j] == grid[i + 1][j + 1];

                // Si le nombre de caractères identiques n'est pas 2, un carré de même couleur peut être formé.
                if (countSame != 2)
                {
                    return true;
                }
            }
        }
        return false;
    }
};