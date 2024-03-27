class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        // Parcours de tous les éléments du vecteur
        for (int i = 0; i < nums.size(); i++)
        {
            // Utilisation d'une variable pour stocker la dernière valeur
            int last = INT_MAX;

            // Boucle tant que l'élément actuel est un nombre positif et qu'il est dans la plage valide
            while (nums[i] >= 1 && nums[i] <= nums.size())
            {
                // Échange de l'élément actuel avec son emplacement attendu
                swap(nums[i], nums[nums[i] - 1]);

                // Vérification si la même valeur se répète
                if (last == nums[i])
                {
                    break; // Sortie de la boucle si la même valeur est rencontrée à nouveau
                }
                // Stockage de la dernière valeur vue
                last = nums[i];
            }
        }

        // Parcours à nouveau du vecteur pour trouver le premier entier positif manquant
        for (int i = 0; i < nums.size(); i++)
        {
            // Si l'élément actuel ne correspond pas à la séquence de nombres attendue
            if (nums[i] != i + 1)
            {
                // Retourne le premier entier positif manquant
                return i + 1;
            }
        }

        // Retourne le prochain entier positif après le plus grand présent dans le vecteur
        return nums.size() + 1;
    }
};