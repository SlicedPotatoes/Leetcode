class Solution
{
  public:
    // Direction pour se déplacer dans la matrice : droite, bas, gauche, haut
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> generateMatrix(int n)
    {
        int size = n * n;

        // Initialiser une matrice n x n avec des zéros
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(n, 0));

        // Définir la position de départ et la direction initiale
        int row = 0;
        int col = -1;
        int d = 0;

        // Remplir les nombres de 1 à n*n dans la matrice
        for (int i = 1; i <= size; i++)
        {
            int currD = d % 4;

            // Déplacer dans la direction actuelle
            row += dir[currD][0];
            col += dir[currD][1];

            // Vérifier si nous avons besoin de changer de direction
            if (row < 0 || row == n || col < 0 || col == n || ans[row][col] != 0)
            {
                // Revenir à la position précédente
                row -= dir[currD][0];
                col -= dir[currD][1];

                // Changer de direction
                d++;
                currD = d % 4;

                // Déplacer dans la nouvelle direction
                row += dir[currD][0];
                col += dir[currD][1];
            }

            // Placer le nombre actuel dans la matrice
            ans[row][col] = i;
        }

        return ans;
    }
};