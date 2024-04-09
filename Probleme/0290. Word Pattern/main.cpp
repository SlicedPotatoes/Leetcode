class Solution
{
  public:
    bool wordPattern(string &pattern, string &s)
    {
        // Map pour associer chaque caractère du motif à un mot dans la chaîne s
        unordered_map<char, string> mp;
        // Ensemble pour vérifier l'unicité des mots
        unordered_set<string> unique;

        // Index pour parcourir le motif
        int indexPattern = 0;
        // Variable pour suivre le début du mot courant dans la chaîne s
        int left = 0;

        // Ajout d'un espace à la fin de la chaîne s pour faciliter le traitement du dernier mot
        s.push_back(' ');

        // Parcours de la chaîne s
        for (int right = 0; right < s.size(); right++)
        {
            // Lorsque nous rencontrons un espace, cela signifie la fin d'un mot
            if (s[right] == ' ')
            {
                // Vérifier si nous avons parcouru tout le motif
                if (indexPattern >= pattern.size())
                {
                    return false;
                }
                // Extraction du mot de la chaîne s
                string _s = s.substr(left, right - left);
                // Vérifier si le caractère actuel du motif a déjà été associé à un mot
                if (mp.find(pattern[indexPattern]) != mp.end())
                {
                    // Si oui, vérifier si le mot actuel correspond au mot associé précédemment
                    if (_s != mp[pattern[indexPattern]])
                    {
                        return false;
                    }
                }
                else
                {
                    // Sinon, vérifier l'unicité du mot dans l'ensemble unique
                    if (unique.contains(_s))
                    {
                        return false;
                    }
                    // Associer le caractère du motif au mot actuel et l'ajouter à l'ensemble unique
                    mp[pattern[indexPattern]] = _s;
                    unique.insert(_s);
                }
                // Mettre à jour la position du début du prochain mot dans la chaîne s
                left = right + 1;
                // Passer au prochain caractère dans le motif
                indexPattern++;
            }
        }

        return indexPattern >= pattern.size();
    }
};