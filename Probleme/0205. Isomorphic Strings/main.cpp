class Solution
{
  public:
    bool isIsomorphic(string s, string t)
    {
        // On utilise un vecteur pour mapper chaque caractère de la première chaîne
        // à son correspondant dans la deuxième chaîne.
        vector<char> mapping(128, -1);          // On utilise 128 car l'ASCII a 128 caractères possibles
        vector<bool> alreadyMapped(128, false); // Pour garder une trace des caractères déjà mappés

        for (int i = 0; i < s.size(); i++)
        {
            // Si le caractère dans la première chaîne n'a pas encore été rencontré,
            if (mapping[s[i]] == -1)
            {
                // on vérifie si le caractère correspondant dans la deuxième chaîne est déjà mappé.
                if (alreadyMapped[t[i]])
                {
                    return false;
                }
                // On fait le mapping du caractère actuel dans la première chaîne avec son correspondant dans la
                // deuxième chaîne.
                mapping[s[i]] = t[i];
                // On marque le caractère correspondant comme déjà mappé.
                alreadyMapped[t[i]] = true;
            }
            // Si le caractère dans la première chaîne est déjà rencontré,
            // on vérifie si son mapping correspond à son équivalent dans la deuxième chaîne.
            if (mapping[s[i]] != t[i])
            {
                return false;
            }
        }

        // Si tous les caractères de la première chaîne ont été mappés de manière cohérente
        // avec la deuxième chaîne, alors les deux chaînes sont isomorphes.
        return true;
    }
};