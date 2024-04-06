class Solution
{
  public:
    bool isAnagram(string &s, string &t)
    {
        // Vérifie si les longueurs des deux chaînes sont différentes
        if (s.size() != t.size())
        {
            // Les chaînes ne peuvent pas être des anagrammes si elles n'ont pas la même longueur
            return false;
        }

        // Crée un vecteur de paires pour stocker le nombre d'occurrences de chaque caractère ('a' - 'z') dans les deux
        // chaînes
        vector<pair<int, int>> vec(26, {0, 0});

        // Parcourt les deux chaînes en même temps pour compter les occurrences de chaque caractère
        for (int i = 0; i < s.size(); i++)
        {
            // Incrémente le compteur pour le caractère courant de la première chaîne (s)
            vec[s[i] - 'a'].first++;
            // Incrémente le compteur pour le caractère courant de la deuxième chaîne (t)
            vec[t[i] - 'a'].second++;
        }

        // Parcourt le vecteur de paires pour vérifier si les occurrences de chaque caractère sont égales dans les deux
        // chaînes
        for (const auto &element : vec)
        {
            if (element.first != element.second)
            {
                return false;
            }
        }

        return true;
    }
};