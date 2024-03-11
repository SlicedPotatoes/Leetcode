class Solution
{
  public:
    // Effectue une recherche binaire pour trouver la première ou la dernière occurrence d'un élément cible dans un
    // vecteur. Elle renvoie l'indice de la première ou de la dernière occurrence selon la valeur du booléen searchEnd.
    int binarySeach(vector<int> &nums, int target, int start, int end, bool searchEnd)
    {
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if ((searchEnd && nums[mid] > target) || (!searchEnd && nums[mid] >= target))
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        if (searchEnd)
        {
            return end;
        }
        return start;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = binarySeach(nums, target, 0, nums.size() - 1, false);  // Recherche de la première occurrence.
        int end = binarySeach(nums, target, start, nums.size() - 1, true); // Recherche de la dernière occurrence.

        // Si le vecteur est vide ou si l'indice de début dépasse l'indice de fin, cela signifie que l'élément cible
        // n'est pas présent.
        if (nums.size() == 0 || start > end)
        {
            // Renvoie {-1, -1} pour indiquer l'absence de l'élément cible.
            return {-1, -1};
        }

        // Renvoie la plage de l'élément cible dans le vecteur.
        return {start, end};
    }
};