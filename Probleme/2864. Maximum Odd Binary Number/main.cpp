class Solution
{
  public:
    string maximumOddBinaryNumber(string &s)
    {
        // Initialisation du compteur pour le nombre de '1' dans la chaîne
        int count = 0;
        for (char c : s)
        {
            if (c == '1')
            {
                // Incrémenter le compteur si le caractère actuel est '1'
                count++;
            }
        }

        // Mettre à jour les caractères de la chaîne pour obtenir le plus grand nombre binaire impair possible
        for (int i = 0; i < count - 1; i++)
        {
            s[i] = '1'; // Remplacer les premiers (count - 1) '0' par '1'
        }
        for (int i = count - 1; i < s.size() - 1; i++)
        {
            s[i] = '0'; // Remplacer le reste de la chaîne par '0'
        }
        s[s.size() - 1] = '1'; // Le dernier chiffre est forcément '1' pour assurer l'impairité
        return s;              // Retourner la chaîne mise à jour
    }
};