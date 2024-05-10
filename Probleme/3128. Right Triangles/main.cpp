class Solution
{
  public:
    long long numberOfRightTriangles(vector<vector<int>> &grid)
    {
        // Initialisation des vecteurs pour compter le nombre de 1 dans chaque ligne et chaque colonne
        vector<int> rows(grid.size(), 0);    // Vecteur pour compter les 1 dans chaque ligne
        vector<int> cols(grid[0].size(), 0); // Vecteur pour compter les 1 dans chaque colonne

        // Parcours de la grille pour compter les 1 dans chaque ligne et chaque colonne
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    cols[j]++; // Incrémente le compteur de 1 dans la colonne j
                    rows[i]++; // Incrémente le compteur de 1 dans la ligne i
                }
            }
        }

        long long ans = 0; // Initialisation de la réponse

        // Parcours de la grille pour compter les triangles rectangles possibles
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    int _rows = rows[i] - 1; // Nombre de 1 dans la ligne i sans compter le point actuel
                    int _cols = cols[j] - 1; // Nombre de 1 dans la colonne j sans compter le point actuel

                    // Ajoute le nombre de triangles possibles avec le point (i, j) comme angle droit
                    ans += _rows * _cols;
                }
            }
        }
        return ans;
    }
};