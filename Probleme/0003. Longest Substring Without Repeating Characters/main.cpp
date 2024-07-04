#include <unordered_map>
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        // unordered_map pour stocker les positions des caractères
        unordered_map<char, int> mp;
        int ans = -1;

        int left = 0; // Pointe vers le début de la fenêtre glissante

        // Parcourir chaque caractère de la chaîne
        for (int right = 0; right < s.size(); right++)
        {
            // Rechercher la position précédente du caractère actuel
            auto it = mp.find(s[right]);

            // Si le caractère est déjà dans la fenêtre actuelle et sa position est >= left
            if (it != mp.end() && it->second >= left)
            {
                // Déplacer le début de la fenêtre après la position de ce caractèr
                left = it->second + 1;
            }

            // Mettre à jour la position actuelle du caractère dans le map
            mp[s[right]] = right;

            // Calculer la longueur actuelle de la sous-chaîne sans répétition et mettre à jour ans
            ans = max(ans, right - left);
        }

        return ans + 1; // Retourner la longueur de la plus longue sous-chaîne sans répétition
    }
};