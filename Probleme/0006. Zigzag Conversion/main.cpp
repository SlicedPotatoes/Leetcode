class Solution
{
  public:
    string convert(string &s, int numRows)
    {
        // Si le nombre de lignes est égal à la taille de la chaîne ou égal à 1,
        // la chaîne reste inchangée, donc nous la retournons immédiatement.
        if (numRows == s.size() || numRows == 1)
        {
            return s;
        }

        // Créer un vecteur de chaînes pour stocker les caractères dans chaque ligne.
        vector<string> rows(numRows);

        // Variable pour suivre la ligne actuelle lors de l'itération à travers la chaîne.
        int currentRow = 0;
        // Variable pour indiquer si nous allons vers le bas ou vers le haut
        bool isGoingDown = true;

        // Itérer à travers chaque caractère de la chaîne.
        for (int i = 0; i < s.size(); i++)
        {
            // Ajouter le caractère à la ligne actuelle.
            rows[currentRow] += s[i];

            // Modifier la ligne actuelle en fonction de la direction (vers le bas ou vers le haut).
            currentRow += isGoingDown ? 1 : -1;

            // Inverser la direction si nous atteignons le haut ou le bas.
            if (currentRow == 0 || currentRow == numRows - 1)
            {
                isGoingDown = !isGoingDown;
            }
        }

        // Réinitialiser la chaîne initiale.
        s = "";

        // Concaténer les lignes dans la chaîne initiale.
        for (string &_s : rows)
        {
            s += _s;
        }

        // Retourner la chaîne résultante.
        return s;
    }
};