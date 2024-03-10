class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0;             // Indice de début de la recherche
        int end = nums.size() - 1; // Indice de fin de la recherche

        // Recherche par dichotomie
        while (start <= end)
        {
            int mid = (start + end) / 2; // Calculer l'indice du milieu

            // Si la valeur à l'indice du milieu est supérieure à la cible
            if (nums[mid] > target)
            {
                end = mid - 1; // Mettre à jour la fin de la plage de recherche
            }
            // Si la valeur à l'indice du milieu est inférieure à la cible
            else if (nums[mid] < target)
            {
                start = mid + 1; // Mettre à jour le début de la plage de recherche
            }
            else
            {
                return mid; // Retourner l'indice si la cible est trouvée
            }
        }

        // Si la cible n'est pas trouvée, retourner la position où elle devrait être insérée
        return start;
    }
};