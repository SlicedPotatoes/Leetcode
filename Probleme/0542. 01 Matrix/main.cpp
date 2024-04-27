class Solution
{
  public:
    // Définition d'une constante pour représenter l'infini
    const int INF = 100000;

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        // Définition des déplacements possibles (haut, gauche, bas, droite)
        vector<int> dy{-1, 0, 1, 0};
        vector<int> dx{0, -1, 0, 1};

        // Parcours de la matrice pour mettre à jour les distances
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    int m = INF; // Initialiser la distance minimale à l'infini

                    // Parcours des cellules voisines (haut et gauche) pour trouver la distance minimale
                    for (int d = 0; d < 2; d++)
                    {
                        int y = i + dy[d];
                        int x = j + dx[d];

                        // Vérifier les limites de la matrice
                        if (y >= 0 && y < mat.size() && x >= 0 && x < mat[0].size())
                        {
                            m = min(m, mat[y][x]); // Mettre à jour la distance minimale
                        }
                    }

                    mat[i][j] = m + 1; // Mettre à jour la distance minimale de la cellule actuelle
                }
            }
        }

        // Parcours de la matrice en sens inverse pour réajuster les distances
        for (int i = mat.size() - 1; i >= 0; i--)
        {
            for (int j = mat[0].size() - 1; j >= 0; j--)
            {
                if (mat[i][j] != 0)
                {
                    int m = INF; // Initialiser la distance minimale à l'infini

                    // Parcours des cellules adjacentes pour trouver la distance minimale
                    for (int d = 0; d < 4; d++)
                    {
                        int y = i + dy[d];
                        int x = j + dx[d];

                        // Vérification des limites de la matrice
                        if (y >= 0 && y < mat.size() && x >= 0 && x < mat[0].size())
                        {
                            // Mise à jour de la distance minimale
                            m = min(m, mat[y][x]);
                        }
                    }

                    // La distance jusqu'à cette cellule est la distance minimale + 1
                    mat[i][j] = m + 1;
                }
            }
        }

        // Retourne la matrice mise à jour avec les distances
        return mat;
    }
};