#include <unordered_map>
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map; // HashMap stockant les nombres déjà rencontrés avec leur indice associé
        // Parcours du vecteur de nombres
        for (int i = 0; i < nums.size(); i++)
        {
            int needed = target - nums[i]; // Calcul du nombre recherché pour atteindre la cible
            // Si le nombre recherché est déjà présent dans la HashMap, retourner son indice ainsi que l'indice actuel
            if (map.find(needed) != map.end())
            {
                return {map[needed], i};
            }

            map[nums[i]] = i; // Ajout du nombre courant dans la HashMap avec son indice associé
        }
        // Si aucune paire de nombres ne satisfait la condition, retourner un vecteur vide
        return {};
    }
};