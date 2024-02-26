class Solution
{
  public:
    bool increasingTriplet(vector<int> &nums)
    {
        int left = INT_MAX; // Plus petite valeur trouvée jusqu'à présent dans le tableau
        int mid = INT_MAX;  // Deuxième plus petite valeur trouvée jusqu'à présent dans le tableau

        for (int element : nums)
        {
            // Si l'élément actuel est plus petit ou égal à la valeur la plus petite trouvée jusqu'à présent
            if (element <= left)
            {
                left = element; // Mettre à jour la valeur la plus petite trouvée
            }
            // Sinon, si l'élément actuel est plus petit que la deuxième plus petite valeur trouvée jusqu'à présent
            else if (element < mid)
            {
                mid = element; // Mettre à jour la deuxième plus petite valeur trouvée
            }
            // Sinon, si l'élément actuel est plus grand que la deuxième plus petite valeur trouvée jusqu'à présent
            else if (element > mid)
            {
                return true; // Un triplet croissant a été trouvé
            }
        }

        return false; // Aucun triplet croissant trouvé
    }
};