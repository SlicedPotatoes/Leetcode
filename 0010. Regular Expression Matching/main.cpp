class Solution
{
  public:
    // La fonction isMatch vérifie si une chaîne s correspond à un motif p donné.
    // Elle utilise une approche récursive avec des indices pour suivre les positions actuelles dans s et p,
    // ainsi que des variables pour garder une trace de la valeur ASCII précédente et du nombre de répétitions.
    bool isMatch(string &s, string &p, int iS = 0, int iP = 0, int lastASCIIValue = -1, int lastASCIICount = -1)
    {
        // Vérifie si nous avons atteint la fin des deux chaînes.
        if (iS >= s.size() && iP >= p.size())
        {
            return true; // Le string S match avec P
        }
        // Vérifie si nous avons atteint la fin d'une des chaînes.
        if (iS >= s.size() || iP >= p.size())
        {
            // Gère le cas où il reste des caractères à traiter dans le motif p.
            if (iP < p.size() && p[iP] == '.' && lastASCIICount != -1)
            {
                return isMatch(s, p, iS, iP + 1, lastASCIIValue, lastASCIICount);
            }
            // Gère le cas où le caractère suivant dans p est multiple ('*').
            if (iP + 1 < p.size() && p[iP + 1] == '*')
            {
                return isMatch(s, p, iS, iP + 2, lastASCIIValue, lastASCIICount);
            }
            // Gère le cas où un motif multiple a supprimé des caractères et qui se trouve entre un motif multiple qui
            // n'a pas supprimé de caractère, suivie d'un char unique
            // exemple s = "aaaa" p = "a*c*a" --> résultat valide avec "aaa" pour "a*", "" pour "c*", "a" pour "a"
            if (iP < p.size() && p[iP] == lastASCIIValue && lastASCIICount > 0)
            {
                return isMatch(s, p, iS, iP + 1, lastASCIIValue, lastASCIICount - 1);
            }
            return false; // Le string S ne match pas avec P
        }
        // Récupère le caractère actuel dans le motif p
        char pattern = p[iP];
        // Gère le cas où le caractère suivant dans le motif p est '*'.
        if (iP + 1 < p.size() && p[iP + 1] == '*')
        {
            // Gère le cas particulier où le caractère actuel est '.'.
            if (pattern == '.')
            {
                // Avance tant que le prochain pattern est multiple ('*')
                int j = iP + 1;
                while (j < p.size() && p[j] == '*')
                {
                    j += 2;
                }
                j--;

                // Recherche dans s une correspondance avec le caractère après '*'.
                int i = iS;
                if (p[j] != '.')
                {
                    while (i < s.size() && s[i] != p[j])
                    {
                        i++;
                    }
                }

                // Effectue une récursion pour toutes les positions possibles après le pattern '*' dans s.
                for (i; i <= s.size(); i++)
                {
                    bool result = isMatch(s, p, i, iP + 2);
                    if (result)
                    {
                        return true;
                    }
                }
                return false; // Le string S ne match pas avec P
            }

            // Effectue une récursion en ignorant le caractère et le pattern multiple du ('*') motif p.
            if (isMatch(s, p, iS, iP + 2, lastASCIIValue, lastASCIICount))
            {
                return true; // Le string S match avec P
            }

            // Trouve toutes les occurrences consécutives du caractère actuel dans s.
            int i = iS;
            while (i < s.size() && s[i] == pattern)
            {
                i++;
            }

            // Avance dans le motif p pour trouver le prochain caractère après '*'.
            int j = iP;
            int count = 0;
            while ((j < p.size() && count <= i - iS) && (p[j] == pattern || p[j] == '*'))
            {
                if (p[j] == '*')
                {
                    count--;
                }
                else
                {
                    count++;
                }
                j++;
            }

            // Vérifie si le caractère après '*' est '.', puis effectue une récursion si nécessaire
            if (j < p.size() && p[j] == '.')
            {
                if (isMatch(s, p, i, j + 1))
                {
                    return true; // Le string S match avec P
                }
            }

            // Effectue une récursion en prenant en compte les répétitions du caractère actuel.
            return isMatch(s, p, i, j, pattern, i - iS);
        }

        // Gère les cas où le caractère actuel dans s correspond au motif ou que le motif est un '.'.
        if (pattern == '.' || s[iS] == pattern)
        {
            return isMatch(s, p, iS + 1, iP + 1);
        }
        return false; // Le string S ne match pas avec P
    }
};