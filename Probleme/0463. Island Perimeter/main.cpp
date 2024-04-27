class Solution
{
  public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        // Initialise la somme du périmètre à 0
        int sum = 0;

        // Parcourir chaque ligne de la grille
        for (int i = 0; i < grid.size(); i++)
        {
            // Parcourir chaque colonne de la grille
            for (int j = 0; j < grid[0].size(); j++)
            {
                // Vérifier si la cellule est une partie de l'île
                if (grid[i][j] == 1)
                {
                    // Si la cellule est sur le bord gauche ou si la cellule à gauche est de l'eau
                    if (j == 0 || !grid[i][j - 1])
                    {
                        sum++; // Ajouter 1 au périmètre
                    }
                    // Si la cellule est sur le bord supérieur ou si la cellule au-dessus est de l'eau
                    if (i == 0 || !grid[i - 1][j])
                    {
                        sum++; // Ajouter 1 au périmètre
                    }
                    // Si la cellule est sur le bord inférieur ou si la cellule en dessous est de l'eau
                    if (i == grid.size() - 1 || !grid[i + 1][j])
                    {
                        sum++; // Ajouter 1 au périmètre
                    }
                    // Si la cellule est sur le bord droit ou si la cellule à droite est de l'eau
                    if (j == grid[0].size() - 1 || !grid[i][j + 1])
                    {
                        sum++; // Ajouter 1 au périmètre
                    }
                }
            }
        }

        return sum;
    }
};