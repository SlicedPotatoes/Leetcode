class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        // Initialisation du vecteur de vecteurs pour stocker le triangle de Pascal
        vector<vector<int>> answer(numRows);
        // Initialisation de la première ligne du triangle de Pascal avec 1
        answer[0] = {1};

        // Boucle pour générer les lignes suivantes du triangle de Pascal
        for (int i = 1; i < numRows; i++)
        {
            vector<int> row(i + 1);
            // Ajout du premier élément de chaque ligne, qui est toujours 1
            row[0] = 1;
            for (int j = 1; j < i; j++)
            {
                // Récupération de l'élément de la ligne précédente et de la colonne précédente
                int a = answer[i - 1][j - 1];
                // Récupération de l'élément de la ligne précédente et de la même colonne
                int b = answer[i - 1][j];

                // Ajout de la somme des deux éléments précédents à la ligne actuelle
                row[j] = a + b;
            }
            // Ajout du dernier élément de chaque ligne, qui est toujours 1
            row[i] = 1;
            answer[i] = row;
        }

        return answer; // Renvoi du triangle de Pascal généré
    }
};