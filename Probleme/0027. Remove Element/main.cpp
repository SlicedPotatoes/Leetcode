class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        // Initialisation de la taille du tableau résultant
        int size = 0;
        // Parcours de la liste des éléments
        for (int i = 0; i < nums.size(); i++)
        {
            // Si l'élément actuel est différent de val
            if (nums[i] != val)
            {
                // On ajoute cet nouvel élément à la fin du nouveau tableau
                nums[size] = nums[i];
                // Et incrémente la taille
                size++;
            }
        }

        // On retourne la nouvelle taille du tableau
        return size;
    }
};