class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        int j = 0; // Index pour parcourir 'needle'

        // Parcourir 'haystack' pour trouver 'needle'
        for (int i = 0; i < haystack.size(); i++)
        {
            // Si le caractère actuel de 'haystack' correspond au caractère actuel de 'needle'
            if (haystack[i] == needle[j])
            {
                j++; // Avancer dans 'needle'
                // Si 'j' atteint la taille de 'needle', cela signifie que 'needle' a été trouvé
                if (j == needle.size())
                {
                    // Retourner l'index du début de la correspondance
                    return i - j + 1;
                }
            }
            else
            {
                // Si une correspondance est rompue, réinitialiser 'j' et ajuster 'i'
                i -= j; // Revenir en arrière de la longueur actuelle de la correspondance
                j = 0;  // Réinitialiser 'j' pour recommencer la comparaison
            }
        }

        // Si 'needle' n'est pas trouvé dans 'haystack', retourner -1
        return -1;
    }
};