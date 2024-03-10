#include <unordered_map>
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int start = 0; // Index de depart du substring
        int best = 0;  // Longeur du plus long substring trouvé

        unordered_map<char, int> seen; // Stocke les caractères déjà rencontrés avec leurs indices
        // Parcours la chaîne caractère par caractère
        for (int j = 0; j < s.size(); j++)
        {
            // Si le caractère actuel est déjà dans la hashmap
            if (seen.find(s[j]) != seen.end())
            {
                int length = j - start; // Calcul de la longueur du substring
                // Si elle est supérieure à la meilleure trouvée, met à jour la valeur de best
                if (length > best)
                {
                    best = length;
                }
                // Si le caractère trouvé est après l'indice de départ du sous-chaîne, met à jour l'indice de départ
                if (seen[s[j]] >= start)
                {
                    start = seen[s[j]] + 1;
                }
            }
            seen[s[j]] = j; // Enregistre le caractère avec son indice dans la chaîne
        }

        // Vérifie s'il reste des caractères non examinés à la fin de la chaîne
        if (best < s.size() - start)
        {
            best = s.size() - start;
        }

        return best;
    }
};