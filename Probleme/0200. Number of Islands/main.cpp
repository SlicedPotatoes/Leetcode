class Solution
{
  public:
    // Vecteurs de déplacement pour naviguer dans les directions (haut, droite, bas, gauche)
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    // Fonction récursive pour explorer une île à partir de la position (i, j)
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        // Marque la case actuelle comme visitée
        grid[i][j] = '2';

        // Parcours les 4 directions possibles
        for (int d = 0; d < 4; d++)
        {
            int y = i + dy[d];
            int x = j + dx[d];

            // Vérifie si la nouvelle position est dans les limites de la grille et si elle contient une île non visitée
            if (y >= 0 && y < grid.size() && x >= 0 && x < grid[0].size() && grid[y][x] == '1')
            {
                // Explore récursivement à partir de cette nouvelle position
                dfs(y, x, grid);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;

        // Parcourt chaque cellule de la grille
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // Si la cellule contient une île non visitée, incrémente le compteur d'îles et explore cette île
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }

        // Retourne le nombre total d'îles trouvées
        return ans;
    }
};