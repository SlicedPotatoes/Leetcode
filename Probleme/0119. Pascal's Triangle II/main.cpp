class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        // Initialisation d'un vecteur 2D pour stocker les lignes du triangle de Pascal
        vector<vector<int>> dp(rowIndex + 1);
        // La première ligne est juste 1
        dp[0] = {1};

        // Boucle pour générer les lignes suivantes du triangle de Pascal
        for (int i = 1; i <= rowIndex; i++)
        {
            // Initialisation d'un vecteur pour stocker la ligne actuelle
            vector<int> row(i + 1);
            // Le premier élément de chaque ligne est 1
            row[0] = 1;

            // Boucle pour remplir les éléments de la ligne actuelle
            for (int j = 1; j < i; j++)
            {
                // Obtenir les valeurs des éléments de la ligne précédente nécessaires pour calculer l'élément actuel
                int a = dp[i - 1][j - 1];
                int b = dp[i - 1][j];
                // Calculer l'élément actuel en additionnant les valeurs des éléments de la ligne précédente
                row[j] = a + b;
            }
            // Le dernier élément de chaque ligne est 1
            row[i] = 1;
            // Stocker la ligne actuelle dans le vecteur 2D
            dp[i] = row;
        }

        // Retourner la ligne spécifiée du triangle de Pascal
        return dp[rowIndex];
    }
};