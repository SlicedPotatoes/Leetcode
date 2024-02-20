class Solution
{
  public:
    string mergeAlternately(string word1, string word2)
    {
        // Récupération de la plus petite longueur
        int minLength = min(word1.size(), word2.size());

        // Initialisation et réservation de la mémoire du nouveau string
        string newString;
        newString.reserve(word1.size() + word2.size());

        // Parcours les strings jusqu'à la longueur du plus petit
        // Concaténation des caractères de manière alternée
        for (int i = 0; i < minLength; i++)
        {
            newString += word1[i];
            newString += word2[i];
        }

        // Ajout du reste de la chaîne la plus longue
        if (word1.size() > word2.size())
        {
            newString += word1.substr(minLength);
        }
        else
        {
            newString += word2.substr(minLength);
        }

        return newString;
    }
};