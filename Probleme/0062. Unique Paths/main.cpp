class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        // Initialisation de deux vecteurs, curr et last, avec des valeurs initiales de 1 pour chaque cellule
        vector<int> curr(n, 1); // Vecteur pour la rangée actuelle
        vector<int> last(n, 1); // Vecteur pour la rangée précédente

        // Parcours de chaque ligne de la grille
        for (int i = 1; i < m; i++)
        {
            // Parcours de chaque colonne de la grille
            for (int j = 1; j < n; j++)
            {
                // Le nombre de chemins uniques pour atteindre la cellule (i, j) est la somme des chemins
                // uniques pour atteindre la cellule précédente à gauche (curr[j - 1]) et la cellule précédente
                // au-dessus (last[j])
                curr[j] = curr[j - 1] + last[j];
            }
            // On échange les vecteurs curr et last pour les mettre à jour pour la prochaine itération
            swap(curr, last);
        }

        // Le résultat final se trouve dans la dernière cellule du vecteur last
        return last[n - 1];
    }
};