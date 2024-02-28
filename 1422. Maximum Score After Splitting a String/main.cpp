class Solution
{
  public:
    int maxScore(string s)
    {
        int prefix = 0; // Initialise un compteur pour le nombre de '0'.

        // Parcourt la chaîne de caractères jusqu'à l'avant-dernier caractère.
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '0')
            {
                prefix++; // Incrémente le compteur si le caractère actuel est '0'.
            }
        }

        // Calcul du score actuel, en ajoutant le nombre de '0' et en vérifiant le dernier caractère.
        int currentScore = prefix + (s[s.size() - 1] == '1' ? 1 : 0);
        // Initialise le résultat avec le score actuel.
        int result = currentScore;

        // Parcourt la chaîne en partant de l'avant-dernier caractère jusqu'au deuxième caractère.
        for (int i = s.size() - 2; i > 0; i--)
        {
            if (s[i] == '0')
            {
                currentScore--; // Décrémente le score si le caractère actuel est '0'.
            }
            else
            {
                currentScore++; // Incrémente le score si le caractère actuel est '1'.
            }
            if (currentScore > result)
            {
                result = currentScore; // Met à jour le résultat si le score actuel dépasse le résultat précédent.
            }
        }

        return result; // Renvoie le score maximal obtenu.
    }
};