class Solution
{
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> set; // Déclaration d'un ensemble non ordonné pour stocker les éléments rencontrés

        // Parcours des éléments jusqu'à la position k
        for (int i = 0; i < nums.size() && i <= k; i++)
        {
            // Vérifie si l'élément actuel est déjà présent dans l'ensemble
            if (set.find(nums[i]) != set.end())
            {
                return true; // Si c'est le cas, il y a un doublon
            }
            set.insert(nums[i]); // Sinon, l'élément est ajouté à l'ensemble
        }

        // Parcours des éléments à partir de la position k+1
        for (int i = k + 1; i < nums.size(); i++)
        {
            set.erase(nums[i - k - 1]); // Supprime l'élément qui dépasse la fenêtre de taille k
            // Vérifie à nouveau si l'élément est présent dans l'ensemble
            if (set.find(nums[i]) != set.end())
            {
                return true; // Si c'est le cas, il y a un doublon
            }
            set.insert(nums[i]); // Ajoute l'élément actuel à l'ensemble
        }

        return false; // Aucun doublon trouvé dans la fenêtre de taille k
    }
};