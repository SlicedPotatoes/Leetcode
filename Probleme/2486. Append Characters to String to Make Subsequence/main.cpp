class Solution
{
  public:
    int appendCharacters(string s, string t)
    {
        int j = 0; // Index pour parcourir la chaîne t

        // Parcours de chaque caractère de s
        for (int i = 0; i < s.size(); i++)
        {
            // Si le caractère actuel de s correspond au caractère actuel de t
            if (s[i] == t[j])
            {
                // Si tous les caractères de t ont été trouvés dans s
                if (++j == t.size())
                {
                    return 0; // Aucun caractère à ajouter
                }
            }
        }

        // Calculer le nombre de caractères restants à ajouter pour que t devienne une sous-séquence de s
        return t.size() - j;
    }
};