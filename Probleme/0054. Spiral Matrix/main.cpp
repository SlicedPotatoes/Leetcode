class Solution
{
  public:
    // Définition des directions pour le mouvement dans la matrice : droite, bas, gauche, haut.
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // Calcul du nombre total d'éléments dans la matrice
        int size = matrix[0].size() * matrix.size();

        // Vecteur pour stocker l'ordre spirale des éléments
        vector<int> ans;

        // Nombre de lignes et de colonnes restantes à parcourir
        int rows = matrix.size() - 1;
        int cols = matrix[0].size();

        // Initialisation des coordonnées pour le parcours de la matrice
        int i = 0;
        int j = -1;

        // Indicateur de la direction actuelle (0: droite, 1: bas, 2: gauche, 3: haut)
        int d = 0;

        // Boucle jusqu'à ce que tous les éléments soient ajoutés à la liste `ans`
        while (ans.size() < size)
        {
            // Calcul de la direction actuelle
            int currD = d % 4;

            // Détermination du nombre d'étapes à effectuer dans la direction actuelle
            int end = (currD == 0 || currD == 2 ? cols-- : rows--);

            // Parcours dans la direction actuelle
            for (int b = 0; b < end; b++)
            {
                i += dir[currD][0]; // Mise à jour de la position verticale
                j += dir[currD][1]; // Mise à jour de la position horizontale

                // Ajout de l'élément courant à la liste des résultats
                ans.push_back(matrix[i][j]);
            }

            // Passage à la direction suivante
            d++;
        }

        // Retourne l'ordre spirale des éléments
        return ans;
    }
};