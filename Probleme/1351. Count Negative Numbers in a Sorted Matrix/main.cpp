class Solution
{
  public:
    // Fonction pour effectuer une recherche binaire dans un vecteur donné
    int binarySearch(vector<int> &row)
    {
        int start = 0;
        int end = row.size() - 1;

        // Boucle de recherche binaire
        while (start <= end)
        {
            int mid = (start + end) / 2;

            // Si l'élément médian est positif ou nul, rechercher dans la partie droite du vecteur
            if (row[mid] >= 0)
            {
                start = mid + 1;
            }
            // Sinon, rechercher dans la partie gauche du vecteur
            else
            {
                end = mid - 1;
            }
        }
        // Retourner le nombre d'éléments négatifs dans le vecteur
        return row.size() - start;
    }

    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;

        // Parcourir chaque ligne de la grille
        for (vector<int> &row : grid)
        {
            // Appeler la fonction de recherche binaire pour chaque ligne et ajouter le nombre d'éléments négatifs
            // trouvés
            count += binarySearch(row);
        }

        // Retourner le nombre total d'éléments négatifs dans la grille
        return count;
    }
};