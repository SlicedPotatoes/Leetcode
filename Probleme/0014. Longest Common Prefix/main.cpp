class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // Initialisation du préfixe commun à une chaîne vide
        string commonPrefix = "";

        // Index utilisé pour parcourir les caractères dans les chaînes
        int index = 0;
        // Variable pour indiquer si nous avons atteint la fin du préfixe commun
        bool end = false;

        // Tant que nous n'avons pas atteint la fin du préfixe commun et que l'index ne dépasse pas la taille de la
        // première chaîne
        while (!end && index < strs[0].size())
        {
            // Caractère actuel à comparer dans toutes les chaînes
            char c = strs[0][index];

            // Parcours des autres chaînes pour vérifier si le caractère actuel est commun à toutes
            for (int i = 1; i < strs.size(); i++)
            {
                // Si l'index dépasse la taille de la chaîne actuelle ou si le caractère actuel ne correspond pas, le
                // préfixe commun prend fin
                if (index > strs[i].size() || strs[i][index] != c)
                {
                    end = true;
                    break;
                }
            }

            // Incrémentation de l'index pour passer au caractère suivant
            index++;

            // Si le préfixe commun n'a pas pris fin à ce stade, ajouter le caractère actuel au préfixe commun
            if (!end)
            {
                commonPrefix += c;
            }
        }

        // Retourner le préfixe commun trouvé
        return commonPrefix;
    }
};