class Solution
{
  public:
    bool canSortArray(vector<int> &nums)
    {
        int curr = __builtin_popcount(nums[0]); // Nombre de bits à 1 dans le premier élément

        int prevMax = -1;      // Maximum précédent initialisé à une valeur invalide
        int minCurr = nums[0]; // Minimum actuel dans le groupe courant
        int maxCurr = nums[0]; // Maximum actuel dans le groupe courant

        // Parcours du tableau
        for (int i = 0; i < nums.size(); i++)
        {
            int nbBits = __builtin_popcount(nums[i]); // Nombre de bits à 1 dans l'élément courant

            // Si le nombre de bits à 1 change
            if (nbBits != curr)
            {
                curr = nbBits; // Met à jour le nombre de bits à 1 courant

                // Vérifie si la plage actuelle est composée de nombres supérieurs à la plage précédente.
                if (minCurr < prevMax)
                {
                    return false;
                }

                prevMax = maxCurr; // Met à jour le maximum précédent
                minCurr = nums[i]; // Initialise le minimum pour le nouveau groupe
                maxCurr = nums[i]; // Initialise le maximum pour le nouveau groupe
            }
            // Si le nombre de bits à 1 est le même que précédemment
            else
            {
                minCurr = min(nums[i], minCurr); // Met à jour le minimum du groupe courant
                maxCurr = max(nums[i], maxCurr); // Met à jour le maximum du groupe courant
            }
        }

        // Retourne true si la dernière plage est composée de nombres supérieurs à la plage précédente; sinon, retourne
        // false.
        return prevMax < minCurr;
    }
};